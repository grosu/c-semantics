module C-DECL-DEFINITION-SYNTAX
     imports C-ABSTRACT-SYNTAX

     syntax KItem ::= declare(K, K) [strict(1)]

     // The declare "backend" implemented in the trans or exec semantics.
     syntax KItem ::= "declare'" "(" K "," K ")" [strict(1)]

     // Turns typedDeclarations into Types in function params.
     syntax Type ::= elideDeclParams(Type) [function]
     syntax List ::= elideList(List) [function]
     syntax Map ::= elideMap(Map) [function]

endmodule

module C-DECL-DEFINITION
     imports C-DECL-DEFINITION-SYNTAX

     imports C-MEMORY-ALLOC-SYNTAX

     imports C-DYNAMIC-SYNTAX
     imports C-SYMLOC-SYNTAX
     imports C-TYPING-SYNTAX
     imports COMPAT-SYNTAX

     // c99 6.7.8:9 Except where explicitly stated otherwise, for the purposes
     // of this subclause unnamed members of objects of structure and union
     // type do not participate in initialization. Unnamed members of
     // structure objects have indeterminate value even after initialization

     // c99 6.7.8:10 If an object that has automatic storage duration is not
     // initialized explicitly, its value is indeterminate. If an object that
     // has static storage duration is not initialized explicitly, then:

     // -- if it has pointer type, it is initialized to a null pointer;

     // -- if it has arithmetic type, it is initialized to (positive or
     // unsigned) zero;

     // if it is an aggregate, every member is initialized (recursively)
     // according to these rules;

     // -- if it is a union, the first named member is initialized
     // (recursively) according to these rules

     context DeclarationDefinition(InitNameGroup(HOLE:KItem, _))

     rule DeclarationDefinition(
               InitNameGroup(T:Type, list(ListItem(K:K) ListItem(K':K) L:List)))
          => DeclarationDefinition(InitNameGroup(T, list(ListItem(K))))
               ~> DeclarationDefinition(InitNameGroup(T, list(ListItem(K') L)))
          [structural]
     rule DeclarationDefinition(
               InitNameGroup(T:Type, list(ListItem(InitName(N:K, Exp:K)))))
          => declare(SingleName(T, N), Exp)
          [structural]

     rule declare(T:Type, K:K) => declare'(elideDeclParams(T), K)
          [structural]

     // Turns param declarators into abstract declarators (i.e., removes ids)
     // and turns VLA params into VLAs of unspecified size.
     rule elideDeclParams(typedDeclaration(T:Type, X:CId))
          => typedDeclaration(elideDeclParams(T), X)
     rule elideDeclParams(t(Mods:Set, functionType(R:Type, Params:List)))
          => t(Mods, functionType(elideDeclParams(R), elideParams(Params)))
     rule elideDeclParams(t(Mods:Set, arrayType(T:Type, N:Int)))
          => t(Mods, arrayType(elideDeclParams(T), N))
     rule elideDeclParams(t(Mods:Set, incompleteArrayType(T:Type)))
          => t(Mods, incompleteArrayType(elideDeclParams(T)))
     rule elideDeclParams(t(Mods:Set, flexibleArrayType(T:Type)))
          => t(Mods, flexibleArrayType(elideDeclParams(T)))
     rule elideDeclParams(t(Mods:Set, unspecifiedArrayType(T:Type)))
          => t(Mods, unspecifiedArrayType(elideDeclParams(T)))
     rule elideDeclParams(t(Mods:Set, variableLengthArrayType(T:Type, N:K)))
          => t(Mods, variableLengthArrayType(elideDeclParams(T), N))
     rule elideDeclParams(t(Mods:Set, pointerType(T:Type)))
          => t(Mods, pointerType(elideDeclParams(T)))
     rule elideDeclParams(T:Type) => T [owise]

     syntax List ::= elideParams(List) [function]
     rule elideParams(ListItem(typedDeclaration(T:Type, _)) Params:List)
          => ListItem(elideDeclParams(T)) elideParams(Params)
     rule elideParams(ListItem(variadic)) => ListItem(variadic)
     rule elideParams(ListItem(t(Mods:Set, variableLengthArrayType(T:Type, _))) Params:List)
          => ListItem(elideDeclParams(t(Mods, unspecifiedArrayType(T)))) elideParams(Params)
     rule elideParams(.List) => .List
     rule elideParams(ListItem(T:Type) Params:List)
          => ListItem(elideDeclParams(T)) elideParams(Params)
          [owise]

     rule elideList(ListItem(T:Type) L:List)
          => ListItem(elideDeclParams(T)) elideList(L)
     rule elideList(.List) => .List

     rule elideMap(K:K |-> T:Type M:Map)
          => K |-> elideDeclParams(T) elideMap(M)
     rule elideMap(.Map) => .Map

endmodule

