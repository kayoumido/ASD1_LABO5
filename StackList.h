//
//  StackList.h
//
//  Labo 5 - StackList
//
//  ASD1 2019
//
//  Dessaules Loïc, Kayoumi Doran, Thurnherr Gabrielle
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

        /**
         * @brief Empty constructor
         */
        StackList(): topNode(nullptr){}

        /**
         * @brief Copy constructor
         * @param stackList The StackList object we want to copy
         * @details call the empty constructor for two reasons :
         * 1. If stacklist in parameter is empty, create a default topNode with nullptr
         * 2. This way, the new Stacklist object is created and when an error comes, the object will be automatically destroy
         */
        StackList(const StackList& stackList) : StackList() {
            if(!stackList.empty()) {
                // /!\ need to allocate new memory for all our node !

                topNode = new Node{nullptr, stackList.topNode->val};

                // Stock the currentNodeThis (from this stacklist) and currentNodeForeign (from stacklist in parameter)
                Node *currentNodeThis = topNode;
                Node *currentNodeForeign = stackList.topNode->nxt;
                // Stop the loop when this is the last node we need to copy
                while (currentNodeForeign != nullptr) {
                    // Create new node with new memory allocation
                    currentNodeThis->nxt = new Node{nullptr, currentNodeForeign->val};
                    // Update needed nodes
                    currentNodeForeign = currentNodeForeign->nxt;
                    currentNodeThis = currentNodeThis->nxt;
                }
            }
        }

        /**
         * @brief Destructor, loop through the stacklist and pop all nodes
         */
        ~StackList(){
            while(!empty()){
                pop();
            }
        }

        /**
         * @brief Check if the StackList is empty
         * @return True if the StcakList is empty, false otherwise
         */
        bool empty() const {
            return topNode == nullptr;
        }

        /**
         * @brief Pop the element on the top of the StackList and delete it
         * @throws StackEmptyException is thrown if we try to pop from an empty StackList
         */
        void pop() {
            if(empty()){
                throw StackEmptyException();
            }

            // re-link the new topNode
            Node* tmp = topNode;
            topNode = topNode->nxt;

            delete(tmp);
        }

        /**
         * @brief Push an element on the top of the StackList
         * @param value The value we want to push in
         */
        void push(const_reference value) {
            Node* newNode = new Node{topNode, value};
            topNode = newNode;
        }

        /**
         * @brief Return the value of the top element of the StackList, this method is used for reading
         * @throws StackEmptyException is thrown if we try to pop from an empty StackList
         * @return The value of the top element of the StackList
         */
        value_type top() const {
            if(empty()){
                throw StackEmptyException();
            }

            return (*topNode).val;
        }

        /**
         * @brief Return the value of the top element of the StackList, this method is used for writing
         * @throws StackEmptyException is thrown if we try to pop from an empty StackList
         * @return A reference on the value of the top element of the StackList
         */
        reference top() {
            if(empty()){
                throw StackEmptyException();
            }

            return (*topNode).val;
        }

        /**
         * @brief Affectation operator between StackList objects
         * @param rhs The StackList on the right of the affectation
         * @return A reference to the current (this) StackList
         */
        StackList& operator=(const StackList& rhs){
            // Prevent for case a1 = a1 => check memory address if same just return the current this object
            if(&rhs != &(*this)) {
                // We'll use the copy constructor to allocate all our new nodes etc...
                // And simply swap our current topNode with the  tmpStack TopNode
                StackList<T> tmpStack = rhs;
                std::swap(topNode, tmpStack.topNode);
            }

            return *this;
        }

    };

};

#endif /* StackList_h */