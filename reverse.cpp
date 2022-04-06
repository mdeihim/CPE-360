#include <iostream>
using namespace std;

class node{
public:
    int input;
    node *next;

    node(){
        input=0;
        next=NULL;
    }
};


class linkedList {
public:
    node *head;
    int length;

    linkedList() {
        head = NULL;
        length = 0;
    }

    void insertAtHead(int x) {   //When adding to the front
        node *temp = new node;
        temp->input = x;
        temp->next = this->head;
        head = temp;
    }

    void insertAtPos(int x, int pos) {
        if (pos > 0 && pos <= this->length + 1) {

            node *temp = new node;
            temp->input = x;

            if (pos == 1) {  //If adding to the front
                insertAtHead(x);
            } else if (pos == this->length + 1) { //If adding to the last place
                node *helper = this->head;
                for (int i = 1; i < length; i++) {
                    helper = helper->next;
                }
                helper->next = temp;
            } else {          //If inserting anywhere in between
                node *helper = head;
                for (int i = 1; i < pos - 1; i++) {
                    helper = helper->next;
                }
                temp->next = helper->next;
                helper->next = temp;
            }
            this->length++;
        }

    }

    void removeFromPos(int pos) {

        if (pos > 0 && pos <= this->length) { //If position exists in current list
            node *helper = this->head;

            if (pos == 1) {      //Chosen position is the first
                this->head = this->head->next;
                delete helper;
            }

            if (pos == this->length) {       //Chosen position is at the end
                for (int i = 1; i < length - 1; i++) {
                    helper = helper->next;
                }
                delete helper->next;
                helper->next = NULL;
            } else {                         //Deleting position in existing list
                node *deleteptr = head;
                for (int i = 1; i < pos; i++) {
                    helper = deleteptr;
                    deleteptr = deleteptr->next;
                }
                helper->next = helper->next->next;
                delete deleteptr;
            }
        } else {
            cout << "Invalid Position" << endl;
        }
    }

    void display() {

        if (head == NULL) {
            cout << "Empty list " << endl;
        } else {
            node *temp;
            temp = head;
            while (temp != NULL) {
                cout << temp->input << ", ";
                temp = temp->next;

            }


        }

    }


    void reverse() { //Reverses the order of the linked list

        node *last = NULL;
        node *next = NULL;
        node *temp = head;


        while(temp != NULL) {
            next = temp->next;
            temp->next = last;
            last = temp;
            temp = next;
        }
        head = last;

    }
};

int main(){
    linkedList listList;
    int input;
    int pos;
    while(1){
        cout<<endl<<"1: Add to list"<<endl;
        cout<<"2: Delete from list"<<endl;
        cout<<"3: Display list"<<endl;
        cout<<"4: Reverse "<<endl;

        int  select=0;
        cin>>select;
        cout<<endl;

        switch(select){
            case 1:
            cout<<"Enter value to add:";
            cin>>input;
            cout<<"Enter position: ";
            cin>>pos;
            listList.insertAtPos(input, pos);
            break;

            case 2:
                cout<<"Enter Position: ";
                cin>>pos;
                listList.removeFromPos(pos);
                break;
            case 3:
                cout<<"Your list: ";
                listList.display();
                break;
            case 4:
                cout<<"List reversed: ";
                listList.reverse();

        }

    }

    return 1;
}
