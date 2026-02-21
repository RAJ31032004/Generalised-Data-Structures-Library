int main()
{
SinglyLLL<int> *obj = new SinglyLLL<int>();

    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);
    
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteFirst();
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->InsertAtPos(105,4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj->DeleteAtPos(4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    delete obj;
    ///////////////////////////////////////////////////////////////////////
    
    ///////////////////////////////////////////////////////////////////////
    
    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');
    
    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',4);

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj->Display();

    cout<<"Number of elements are : "<<dobj->Count()<<"\n";
    
    delete dobj;
    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

SinglyCLL<int> *scobj = new SinglyCLL<int>();

scobj->InsertFirst(11);
scobj->InsertFirst(21);
scobj->InsertFirst(51);

scobj->Display();
cout<<"Number of elements are : "<<scobj->Count()<<"\n";

scobj->InsertLast(101);
scobj->InsertLast(111);

scobj->Display();
cout<<"Number of elements are : "<<scobj->Count()<<"\n";

scobj->InsertAtPos(75,3);

scobj->Display();
cout<<"Number of elements are : "<<scobj->Count()<<"\n";

scobj->DeleteFirst();

scobj->Display();
cout<<"Number of elements are : "<<scobj->Count()<<"\n";

scobj->DeleteLast();

scobj->Display();
cout<<"Number of elements are : "<<scobj->Count()<<"\n";

scobj->DeleteAtPos(3);

scobj->Display();
cout<<"Number of elements are : "<<scobj->Count()<<"\n";

delete scobj;

/////////////////////////////////////////////////////////////////////////////////////////
   ///////////////////////////////////////////////////////////////////////////////////////

    DoublyCLL<int> *dcobj = new DoublyCLL<int>();

    dcobj->InsertFirst(10);
    dcobj->InsertFirst(20);
    dcobj->InsertFirst(30);

    dcobj->Display();
    cout<<"Number of elements are : "<<dcobj->Count()<<"\n";

    dcobj->InsertLast(40);
    dcobj->InsertLast(50);

    dcobj->Display();
    cout<<"Number of elements are : "<<dcobj->Count()<<"\n";

    dcobj->InsertAtPos(25,3);

    dcobj->Display();
    cout<<"Number of elements are : "<<dcobj->Count()<<"\n";

    dcobj->DeleteFirst();

    dcobj->Display();
    cout<<"Number of elements are : "<<dcobj->Count()<<"\n";

    dcobj->DeleteLast();

    dcobj->Display();
    cout<<"Number of elements are : "<<dcobj->Count()<<"\n";

    dcobj->DeleteAtPos(3);

    dcobj->Display();
    cout<<"Number of elements are : "<<dcobj->Count()<<"\n";

    delete dcobj;

    //////////////////////////////////////////////////////////////////////////////////////////////
     Stack<char> *sobj = new Stack<char>();

    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');
    
    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Return value of peep is : "<<sobj->peep()<<"\n";

    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Poped element is : "<<sobj->pop()<<"\n";
    
    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Poped element is : "<<sobj->pop()<<"\n";
    
    sobj->Display();

    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    sobj->push('e');

    sobj->Display();
    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";

    delete sobj;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////
    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);

    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    
    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    
    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    qobj->enqueue(121.56789);

    qobj->Display();

    cout<<"Number of elements in queue are : "<<qobj->Count()<<"\n";

    delete qobj;
    
    return 0;
}
