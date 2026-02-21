///////////////////////////////////////////////////
//      Generalised Data Structure Library
///////////////////////////////////////////////////

/*
---------------------------------------------------------------------------------------
Type                    Name of class for node      Name of class for Functionality
---------------------------------------------------------------------------------------
Singly Linear            SinglyLLLnode               SinglyLLL          Done
Singly Cirular           SinglyCLLnode               SinglyCLL          Done
Doubly Linear            DoublyLLLnode               DoublyLLL          Done
Doubly Circular          DoublyCLLnode               DoublyCLL
Stack                    Stacknode                   Stack              Done
Queue                    Queuenode                   Queue              Done
---------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//          Singly Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:        
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)  
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Display node values
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to count number of nodes
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> ::Count()
{
    return this->iCount;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> ::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}


//////////////////////////////////////////////////////////////////////
//          Singly Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////


template <class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;

        last->next = first;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;

        last->next = first;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to display all nodes in the list
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct SinglyCLLnode<T> * temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != last ->next);
    
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to count number of nodes in the list
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}


////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////
//          Doubly Linear Linlked List using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertLast(T no) 
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;    
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteFirst()
{
    if(this->first == NULL)                 // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)      // LL contains 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    // LL contains more than 1 node
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

template<class T>
void DoublyLLL<T> ::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)                 // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)      // LL contains 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    // LL contains more than 1 node
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;    
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> ::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }    
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to display node at position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyLLL<T> ::Display()
{
    DoublyLLLnode<T> *temp = NULL;
    
    temp = this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}



/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Count nodes
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> ::Count()
{
    return this->iCount;

}

///////////////////////////////////////////////////////////////////////
//          Doubly Circular Linlked List using Generic Approach
///////////////////////////////////////////////////////////////////////
#pragma pack(1)
template<class T>
class DoublyCLLnode
{
public:
    T data;
    DoublyCLLnode<T> *next;
    DoublyCLLnode<T> *prev;

    DoublyCLLnode(T no)
    {
        data = no;
        next = NULL;
        prev = NULL;
    }
};

template<class T>
class DoublyCLL
{
private:
    DoublyCLLnode<T> *first;
    DoublyCLLnode<T> *last;
    int iCount;

public:
    DoublyCLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DoublyCLL
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to initialize data members
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

    if(first == NULL)
    {
        first = last = newn;
        first->next = first;
        first->prev = first;
    }
    else
    {
        newn->next = first;
        newn->prev = last;

        first->prev = newn;
        last->next = newn;

        first = newn;
    }
    iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

    if(first == NULL)
    {
        first = last = newn;
        first->next = first;
        first->prev = first;
    }
    else
    {
        newn->next = first;
        newn->prev = last;

        last->next = newn;
        first->prev = newn;

        last = newn;
    }
    iCount++;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at first position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(first == NULL)
        return;

    else if(first == last)
    {
        delete first;
        first = last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;

        first->prev = last;
        last->next = first;
    }
    iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at last position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if(first == NULL)
        return;

    else if(first == last)
    {
        delete last;
        first = last = NULL;
    }
    else
    {
        last = last->prev;
        delete first->prev;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertAtPos(T no,int pos)
{
    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
        InsertFirst(no);
    else if(pos == iCount+1)
        InsertLast(no);
    else
    {
        DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);
        DoublyCLLnode<T> *temp = first;

        for(int i=1;i<pos-1;i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node at position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
        DeleteFirst();
    else if(pos == iCount)
        DeleteLast();
    else
    {
        DoublyCLLnode<T> *temp = first;

        for(int i=1;i<pos;i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to display all nodes in the list
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::Display()
{
    if(first == NULL)
        return;

    DoublyCLLnode<T> *temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Count nodes
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}


///////////////////////////////////////////////////////////////////////
//                  Stack using Generic Approach
///////////////////////////////////////////////////////////////////////


#pragma pack(1)
template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();

        void push(T);     
        T pop();
        T peep();
        void Display();
        int Count();
};

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Stack
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to create Stack
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created succesfully...\n";

    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     push
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     pop
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node from first position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////


template<class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return T();
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}   

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     peep
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to get value of first node
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return T();
    }

    Value = this->first->data;    
    return Value;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to display node values
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to Count nodes
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}



////////////////////////////////////////////////////////////////////////////////
//                         Queued using Generic Approach
///////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Queuenode
{
    public:
          T data;
          Queuenode<T> *next;

          Queuenode(T no)
          {
                this->data = no;
                this->next = NULL;
          }
};

template<class T>

class Queue
{
    private:
        Queuenode<T> * first;
        Queuenode<T> * last;
        int iCount;
    public:
        Queue();
        
        void enqueue(T);                 // InsertLast
        T dequeue();                      // DeleteFirst
        void Display();
        int Count();
};


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Queue
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to create Queue
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created Successfully...\n";
    this->first = NULL;
    this->last =NULL;
    this->iCount = 0;
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     enqueue
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at last position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: enqueue(T no)   
{
    Queuenode<T> * newn = NULL;

    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    }

    this->iCount++;
    
}  


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     dequeue
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to delete node from first position
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"queue is Empty\n";
        return T();
    }
    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}             


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to display node values
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> ::Display()
{
    Queuenode<T> * temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}


/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to count number of nodes in queue
//  Author :            Raj Samir Jadhav
//  Date :              06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T> ::Count()
{
    return this->iCount;
}

//////////////////////////////// End of Library //////////////////////////////////

