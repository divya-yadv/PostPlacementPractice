
// recursive approach
   Node* flatten(Node* head) {
        if (!head) return nullptr;
        Node* tail = head;
        
        Node* next1 = flatten(head->child);
        Node* next2 = flatten(head->next);

        if (next1) {
            tail->next = next1;
            while (tail->next) {
                tail->next->prev = tail;
                tail->child = nullptr;
                tail = tail->next;
            }
        }
        
        tail->next = next2;
        if (next2) {
            next2->prev = tail;
        }
        
        return head;
    }

Node* flatten(Node* head) {
        Node *temp = head, *runner, *nextPtr;
        while(temp)
        {
            if(temp->child)
            {
                nextPtr = temp->next;
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = NULL;
                runner = temp->next;
                
                while(runner->next)
                {
                    runner = runner->next;
                }
                runner->next = nextPtr;
                if(nextPtr) nextPtr->prev = runner;
            }
            temp = temp->next;
        }
        return head;
    }


