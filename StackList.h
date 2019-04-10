//
//  StackList.h
//

#ifndef StackList_h
#define StackList_h

#include <utility>

namespace asd1 {

    class StackEmptyException { };

    template<typename T>
    class StackList {
    public:
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;

    private:
        struct Node {
            Node* nxt;
            value_type val;
        };
        Node* topNode;

    public:

        StackList(){
            topNode = new Node {nullptr, 0};
        }

        StackList(const StackList& stackList){
            topNode = stackList.topNode;
        }

        ~StackList(){
            delete(topNode);
        }

        bool empty() const {
        }

        void pop() {
        }

        void push(const_reference) {
        }

        value_type top() const {
            return (*topNode).val();
        }

        reference top() {
            return (*topNode).val();
        }

        reference operator=(const_reference rhs){

        }

    };

// A compléter sans ajouter d'attributs privés et sans utiliser le type T
// autrement que via les types value_type, reference et const_reference
//
// vous devez mettre en oeuvre le constructeur par défaut, le destructeur,
// les méthodes push, pop, top et empty, ainsi que le constructeur de copie
// et l'opérateur d'affectation par copie. Quand c'est pertinent, il faut
// lever l'exception StackEmptyException
//
// Cette classe doit offrir garanties faible et forte pour toutes ses
// fonctionalités

    };

#endif /* StackList_h */