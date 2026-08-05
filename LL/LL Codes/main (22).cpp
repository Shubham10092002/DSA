#include <iostream>
using namespace std;

class Node {
        
        public:
        int data;
        Node* next;

        Node() {
                this->data = 0;
                this->next = NULL;
        }
        Node(int data) {
                this->data = data;
                this->next = NULL;
        }

        //TODO: Write a destrcutor to delete a node
        ~Node() {
                //write your code here
                cout << "Node with value: " << this->data << "deleted" << endl;
        }
};

//I want to insert a node right at the head of Linked List
void insertAtHead(Node* &head, Node* &tail, int data) {
        //check for Empty LL
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
        }
        else {
                //step1:
                Node* newNode = new Node(data);
                //step2:
                newNode -> next = head;
                //step3:
                head = newNode;
        }


}
//I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node* &head,Node* &tail, int data) {
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                return;
        }
        //step1: creatae a node
        Node* newNode = new Node(data);
        //step2: connect woth tail ndoe
        tail->next = newNode;
        //step3: update tail;
        tail = newNode;
}
void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
}

int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}

void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                return;
        }
        //step1: find the position: prev & curr;

        if(position == 0) {
                insertAtHead(head, tail , data);
                return;
        }
       
        int len = findLength(head);
        
        if(position >= len) {
                insertAtTail(head, tail, data);
                return;
        }
        //ste1:find prev and curr
        int i = 1;
        Node* prev = head;
        while(i < position) {
                prev= prev -> next;
                i++;
        }
        Node* curr = prev -> next;

        //step2;
        Node* newNode = new Node(data);

        //step3:
        newNode -> next = curr;

        //step4:
        prev -> next = newNode; 
        
}

void deleteNode(int position, Node* &head, Node* &tail) {
        if(head == NULL) {
                cout << "Cannot delete, LL is empty";
                return;
        }

        //deleting first node
        if(position == 1) {
                Node* temp = head;
                head = head -> next;
                temp -> next = NULL;
                delete temp;
                return;
        }

        int len  = findLength(head);


        //deleting last node
        if(position == len) {
                //find prev
                int i = 1;
                Node* prev = head;
                while(i < position - 1) {
                        prev = prev->next;
                        i++;
                }
                //step2:
                prev->next = NULL;
                //step3:
                Node* temp = tail;
                //step4:
                tail = prev;
                //step5:
                delete temp;
                return;
        }

        //deleting middle node

        //step  : find prev and curr
        int i =1;
        Node* prev = head;
        while( i < position-1) {
                prev= prev -> next;
                i++;
        }

        Node* curr = prev -> next;

        //step2:
        prev -> next = curr -> next;
        //step3:
        curr -> next = NULL;
        //step4:
        delete curr;

}

int main() {

        Node* head = NULL;
        Node* tail = NULL;
        insertAtHead(head, tail,20);
        insertAtHead(head, tail,50);
        insertAtHead(head, tail,60);
        insertAtHead(head,tail, 90);
        insertAtTail(head, tail, 77);

        print(head);
        cout << endl;
        // cout << "head: " << head -> data << endl;
        // cout << "tail: " << tail->data << endl;

        // insertAtPosition(101, 5, head, tail);
        // cout<< "Printing after insert at position call" << endl;
        // print(head);
        // cout << endl;
        // cout << "head: " << head -> data << endl;
        // cout << "tail: " << tail->data << endl;

        deleteNode(9, head, tail);
        cout << endl;
        print(head);
        cout << endl;

        return 0;
}



////////////////////////////////////////////////

    void deletehead(ListNode* &head ){
        ListNode* temp= head;
        head= head->next;
        temp->next=NULL;
        delete temp;
        return;
        
    }
    
    
    void deletemiddle(int pos,ListNode* &head){
         ListNode* temp= head; 
    
        while(pos){
           temp=temp->next;
            pos--;
        }
        temp->next=temp->next->next;
        return;
        
    }
    
    void deleteend(int pos,  ListNode* &head){
         ListNode* temp= head; 
        while(pos){
            temp=temp->next;
            pos--;
        }
        //mp->next=NULL;
        return;
    }
        
    
        
        
    
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int ,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        ListNode* temp = head;
        ListNode* temp2= head;
      // ListNode* temp3= head;
        int count=0;
        
        while(temp!=NULL)
        {   count++;
            temp=temp->next;
        } 
    // temp=head;
        int pos=1;
        
        while(temp!=NULL && temp->next !=NULL){
            int data = temp->val;
            
            
            if(mp.find(data)!=mp.end()){
                if(pos==1){
                    //delete head node
                    deletehead(temp2);
                    count--;
                    
                }
                else if(pos< count){
                    //delete middle element
                    deletemiddle(pos-1,temp2);
                    pos++;
                }
                else{
                    //delete end
                    deleteend(pos-1,temp2);
                    
                    
                }
            }
            
            else{
                pos++;
            }
           
            temp=temp->next;
        }
        return temp2;