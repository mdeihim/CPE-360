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

class linkedList{
public:
    node *head;

    linkedList(){
        head=NULL;

    }

    int getlength(){
        int count=0;
        node *current = head;

        while(current != NULL){
            count++;
            current=current->next;
        }
        return count;
    }

    void testLoop(){   //Linked list for testing
        head = new node;
        head->next = new node;
        head->next->next = new node;
        head->next->next->next = new node;
        head->input=15;
        head->next->input=20;
        head->next->next->input=4;
        head->next->next->next->input=10;

        head->next->next->next->next = head->next->next;  //Creates a loop in the list


    }


    void display(){

        if(head==NULL){
            cout<<"Empty list "<<endl;
        }

        else{
                node *temp;
                temp =head;
                while(temp!=NULL){
                    cout<<temp->input<<", ";
                    temp= temp->next;

                }
    }


    }


   //  Originally I tried using the getLength function to loop through the list using the fast and slow pointers

    void detectAndRemoveLoop(){
        node *slow = head;
        node *fast = head;
        if(head==NULL){
          cout<<"NO LIST ";
        }
        for(int i=0; i < getlength(); i++)
        {
            fast = fast->next;  //Fat pointer iterates through the linked list
        }

        while(fast->next != slow->next)   //If there is no loop slow moves to next node and fast to next node
        {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = NULL; // removes loop
    }


        /*
        node *fast=head;
        node *slow=head;

        if(head==NULL){
            cout<<"No List: "<<endl;
        }
        else{

            for(int i=1; i<this->getlength(); i++){
                fast=fast->next;
            }
            if(fast->next==NULL){
                cout<<"No loop in the list "<<endl;
            }
            else if(fast->next==slow){
                cout<<"Loop at beginning of list"<<endl;
                fast->next=NULL;
            }
            else{
                cout<<"A loop exists. "<<endl;
                for(int i=1; i<=this->getlength();i++){
                    if(fast==slow){
                     slow=head;
                        cout<<"A loop exists. "<<endl;
                        fast->next=NULL;
                    }
                }
            }


       }
    } */


};





int main(){
    //need to add a test loop to input
    linkedList listList;
    listList.testLoop();

    int input;
    int pos;
    while(1){
        cout<<endl<<"1: Get Length of list "<<endl;
        cout<<"2: Remove all loops from list "<<endl;


        int  select=0;
        cin>>select;
        cout<<endl;

        switch(select){
            case 1:
            cout<<"Length:"<<endl;
            cout<<listList.getlength()<<endl;

            break;

            case 2:
                cout<<"List after loops are removed: ";
                listList.detectAndRemoveLoop();  //stuck here
                listList.display();
                cout<<endl;


        }

    }

    return 1;
}
