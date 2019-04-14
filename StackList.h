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
            topNode = nullptr;
        }


        StackList(const StackList& stackList){
            if(stackList.empty()) {
                topNode = nullptr;
            }
            // Otherwise, keep the current stacklist but create entire new nodes emplacement
            else {
                // /!\ need to allocate new memory for all our node ! We have pointer, so two pointer must not point on the same memory area

                // Create our new topNode
                topNode = new Node(*(stackList.topNode));
                // Stock the currentNodeThis (from this stacklist) and currentNodeForeign (from stacklist in parameter)
                Node* currentNodeThis = topNode;
                Node* currentNodeForeign = stackList.topNode;
                // Stop the loop when this is the last node we need to copy
                while (currentNodeForeign->nxt != nullptr) {
                    // Create new node with new memory allocation
                    currentNodeThis->nxt = new Node(*(currentNodeForeign->nxt));
                    // Update needed nodes
                    currentNodeForeign = currentNodeForeign->nxt;
                    currentNodeThis = currentNodeThis->nxt;
                }
            }
        }

        ~StackList(){
            while(!empty()){
                pop();
            }
        }

        bool empty() const {
            return topNode == nullptr;
        }

        void pop() {
            if(empty()){
                throw StackEmptyException();
            }

            Node* tmp = topNode;
            topNode = topNode->nxt;

            delete(tmp);
        }

        void push(const_reference value) {
            Node* newNode = new Node{topNode, value};
            topNode = newNode;
        }

        value_type top() const {
            if(empty()){
                throw StackEmptyException();
            }

            return (*topNode).val;
        }

        reference top() {
            if(empty()){
                throw StackEmptyException();
            }

            return (*topNode).val;
        }

        StackList& operator=(const StackList& rhs){
            // For the = operator, we'll use the copy constructor to allocate all our new nodes etc...
            // And simply swap our current topNode with the new stack TopNode that will never be use somewhere else
            StackList<T> newSTack = rhs;
            std::swap(topNode, newSTack.topNode);
            return *this;
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