ADT_List
========

An implementation of a a linked list following the ADT specifications of a list, as specified by Aho, Hopcroft, and Ullman in *Data Structures and Algorithms*, including an "artificial head" and the given ADT operations. There are two implementations provided. Under the int directory is a plain integer linked list. Under the generic directory is the much more interesting generic linked list.

The generic linked list essentially provides a C++-style way of templating the linked list. Given a type, a preprocesor macro will create different versions of the linked list and its functions for that the specified type. In other words, given a call to the macro as follows:

    MAKE_LIST_TYPE(type)

The following types will be created:

    typeList
    
    type_list_position
  
And the following functions will be created:

    void type_list_initialize(typeList *)
      (initialize a typeList; must be called  on List before using)
  
    void type_list_uninintialize(typeList *)
      (uninitialize a typeList; must be called when done with list)
  
    type_list_position type_list_first(typeList *)
      (get the position of the first element of the list)
    
    type_list_position type_list_end(typeList *l)
      (get the position of one beoyind the last element of the last)
    
    uint8_t type_list_is_end(type_list_position)
      (determine if the given position is at the end of the list)
    
    uint8_t type_list_is_beginning(typeList *, type_list_position)
      (doesn't really return anything sensible right now; avoid currently)
    
    type_list_position type_list_next(type_list_position)
      (returns the position of the next element)
    
    type_list_position type_list_previous(type_list_position)
      (returns the position of the previous element)
    
    type_list_position type_list_locate(typeList *, type)
      (returns position of element with given value if list contains it or end of list otherwise)
      
    void type_list_insert(type, type_list_position)
      (inserts the given value into the list at the given position specified by type_list_position)
      
    void type_list_delete(type_list_position)
      (deletes the element at the given position from the list)
      
    typ type_list_retrieve(type_list_position)
      (gets the data value at the position specified by the type_list_position)
      
As noted above, this does C++ style templating and will therefore actually create and compile separate functions for evry call to the macro, just as in C++ templates.
      
This completely specifies the behavior of a typeList list created from this macro. If these lists are to be used in multiple different modules, the expansion of the macro should be probably be done in a header file, with header guards, and included in the different modules, because the macro does not prevent problems with redeclaraing the same list type. Please see the generic/intList.h and generic/uint64_tList.h files for examples, with the generic/main.c file as an example of a file using these types.

As another note, currently, if the type that is to be used for the data in the List contains a pointer (e.g., char \*), then you'll have to typedef that beforehand and pass the typedef to the MAKE_LIST_TYPE macro. See the example at the top of main.c with a char * typedef.
