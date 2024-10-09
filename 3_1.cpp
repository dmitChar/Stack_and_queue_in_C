
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>  

using namespace std;
const int N = 100;
const int M = 3;


struct stack {
    int elem[N][3] {0};
    int top;
}; 

struct Node
{
    int priority;
    int takstime;
    int durationtime;
    
    Node* Next;                      
};

        //СТЕК

void pushFromQ(stack* stk, Node *n, bool *stfree, bool *qufree) {

    if (stk->top < N) {
        
        stk->elem[stk->top][0] = n->takstime;
        stk->elem[stk->top][1] = n->priority;
        stk->elem[stk->top][2] = n->durationtime;
        stk->top++;
        *stfree = false;
        *qufree = true;
    }
    else cout << "Стек переполнен. Количество элементов: " << stk->top;
}

void pushFromProc(stack *stk, Node * n, bool* stfree) {

    if (stk->top < N) {

        stk->elem[stk->top][0] = n->takstime;
        stk->elem[stk->top][1] = n->priority;
        stk->elem[stk->top][2] = n->durationtime;
        stk->top++;
        *stfree = false;
        
    }
}

void pop(stack* stk, Node *n) {

    if ((stk->top) > 0) {

        stk->top--;
        n->takstime = stk->elem[stk->top][0];
        n->priority = stk->elem[stk->top][1]; 
        n->durationtime = stk->elem[stk->top][2];
    }   
}

bool stIsempty(stack* stk) {
    if (stk->top == 0)return true;
    else return false;
}

void stkPrint(stack* stk) {
    int i = stk->top;
    cout << "Содержимое стека:" << endl;
    if (!stIsempty(stk)) 
    do {
        i--;
        
        cout << "Время поступления задачи: " << stk->elem[i][0] << "; Приоритет задачи: " << stk->elem[i][1] << "; Такты задачи: " << stk->elem[i][2]<<endl;
    } while (i > 0);
}



// ОЧЕРЕДЬ

class List
{
    Node* Head, * Tail;                  //Указатели на начало списка и на конец
public:
    List() :Head(NULL), Tail(NULL) {};    //Инициализация указателей как пустых
    ~List();                           //Деструктор для освобождения памяти от всего что будет
    void Add(int, int, int);                   //Функция заполнения структуры Node и добавления её в список как элемента
    void del();
    void qshow(string s);
    Node* getHead();
    Node* gettail();


};

Node* List::gettail() {
    return Tail;
}

Node* List::getHead() {
    return Head;
}

List::~List() //ДЕСТРУКТОР ДЛЯ ОЧИСТКИ ПАМЯТИ
{
    Node* temp = Head;                     //Временный указатель на начало списка
    while (temp != NULL)                   //Пока в списке что-то есть

    {
        temp = Head->Next;                 //Резерв адреса на следующий элемент списка

        delete Head;                       //Освобождение памяти от первой структуры как элемента списка

        Head = temp;                       //Сдвиг начала на следующий адрес, который берем из резерва

    }
}


//ФУНКЦИЯ ЗАПОЛНЕНИЯ ИНФОРМАЦИОННЫХ ПОЛЕЙ СТРУКТУРЫ NODE И ДОБАВЛЕНИЯ ЭТОЙ СТРУКТУРЫ В СПИСОК

void List::Add(int time, int pr, int durtime)
{
    Node* temp = new Node;              //Выделение памяти для нового звена списка
    temp->priority = pr;
    temp->takstime = time;
    temp->durationtime = durtime;

    
    temp->Next = NULL;                  //Указание, что следующее звено новосозданной структуры пока пустое

    if (Head != NULL)                   //Если список не пуст
    {
        Tail->Next = temp;              //Указание, что следующее звено списка это новосозданная структура
        Tail = temp;
    }
    else Head = Tail= temp;      //Если список пуст, добавление первого элемента
}


void List::qshow(string s) {

    cout << "Содержимое " << s << " очереди:" << endl;
    Node* temp = Head;
    while (temp != NULL)
    {
        cout << "Время поступления задачи " << temp->takstime << "; Приоритет задачи: " << temp->priority << "; Такты задачи: " << temp->durationtime << endl;
        temp = temp->Next;
    }
}

void List::del()
{
    if (Head != NULL)                  
    {
        Node* temp = Head;              
       
        Head = Head->Next;    

                           
    }
}

void processor(Node* n, bool* prisfree) {

    n->durationtime--;

    if (n->durationtime == 0)
        *prisfree = true;
    else *prisfree = false;
}



void procshow(Node *n) {
    cout << "Содержимое процессора:" << endl;
    cout << "Время поступления задачи: " << n->takstime << "; Приоритетность: " << n->priority << "; Такты задачи: " << n->durationtime << endl;
}

void print(int n, int m, int** a)
{
    cout << "Входные параметры:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) {
            switch (j) {
            case 0: 
                cout << "Время поступления задачи: " << a[i][j] << "; ";
                break;

            case 1: 
                cout << "Приоритет задачи: " << a[i][j] << "; ";
                break;

            case 2: 
                cout << "Такты задачи: " << a[i][j] << "; ";
                break;
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isemp(List &q1, List &q2, List &q3) {
    if ((q1.getHead()) != NULL || (q2.getHead()) != NULL || (q3.getHead()) != NULL)
        return false;
    else return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream fr;
    fr.open("I:\\Text.txt");
    List Queue1;
    List Queue2;
    List Queue3;
    stack* st = new stack;
    st->top = 0;

    Node* q1 = NULL;
    Node* q2 = NULL;
    Node* q3 = NULL;
    int time, takts, prior;
    int prtakt = 0;
    int numberOfTasks = 0;
    int countq = 0;
    bool inq = false;
    bool qufree = true;
    bool procfree = true; bool stfree = true;
    const int row = 5;
    const int col = 3;
    int** tasks = new int* [row];
    for (int i = 0; i < row; i++) {
        tasks[i] = new int[col];
    }
    int pr[3] = { 0 };
    int c = 0;

    Node* q = NULL;
   
    Node* current = NULL;
    

    int i = 0;
    if (fr.is_open())
    {
        while (!fr.eof())
        {
            fr >> time;
            fr >> takts;
            fr >> prior;
            if (numberOfTasks < row) {
                tasks[i][0] = time;
                tasks[i][1] = takts;
                tasks[i][2] = prior;
                numberOfTasks++;
            }
            else cout << "Переполнение очереди" << endl;
            i++;
        }
    }
    else cout << "Файл не открыт";

    print(i, col, tasks);
    int tact = 1;

    do {
       
        if (countq < numberOfTasks) {

            switch (tasks[countq][1]) {
            case 3:
                Queue1.Add(tasks[countq][0], tasks[countq][1], tasks[countq][2]);
                q1 = Queue1.getHead();
                countq++;

                break;

            case 2:
                Queue2.Add(tasks[countq][0], tasks[countq][1], tasks[countq][2]);
                q2 = Queue2.getHead();
                countq++;

                break;

            case 1:
                Queue3.Add(tasks[countq][0], tasks[countq][1], tasks[countq][2]);
                q3 = Queue3.getHead();
                countq++;

                break;
            }
        }

            if (q3 != NULL) {
                q = Queue3.getHead(); 
                c = 3;
                
            }

             if (q2 != NULL) {
                q = Queue2.getHead();
                c = 2;
            }

             if (q1 != NULL) {
                q = Queue1.getHead();
                c = 1;
            }
        
        if ( !procfree) {
            if (q != NULL){
                if (q->priority > current->priority) {
                    pushFromProc(st, current, &stfree);
                    current = q;
                    q = NULL;
                    Node* t = NULL;
                    switch (c) {

                    case 1:
                        
                        t = Queue1.getHead();
                        q1 = t->Next;
                        Queue1.del();
                        break;

                    case 2:
                        
                        t = Queue2.getHead();
                        q2 = t->Next;
                        Queue2.del();
                        break;

                    case 3:
                        
                        t = Queue3.getHead();
                        q3 = t->Next;
                        Queue3.del();
                        break;
                    }
                    
                    processor(current, &procfree);
                    
                }
                else {
                    processor(current, &procfree);
                    
                }
            }
            else {
                processor(current, &procfree);
                
            }

          
        } 
        else if (procfree && q != NULL && stIsempty(st)) {
        current = q;
        q = NULL;
        Node* t = NULL;
        switch (c) {

        case 1:

            t = Queue1.getHead();
            q1 = t->Next;
            Queue1.del();
            break;

        case 2:

            t = Queue2.getHead();
            q2 = t->Next;
            Queue2.del();
            break;

        case 3:

            t = Queue3.getHead();
            q3 = t->Next;
            Queue3.del();
            break;
        }
            
            processor(current, &procfree);
        }
       
        else if ( procfree && q!= NULL  && !stIsempty(st)) {
            if (q->priority >= st->elem[st->top-1][1] ) {
                current = q;
                q = NULL;
                Node* t = NULL;
        switch (c) {

        case 1:

            t = Queue1.getHead();
            q1 = t->Next;
            Queue1.del();
            break;

        case 2:

            t = Queue2.getHead();
            q2 = t->Next;
            Queue2.del();
            break;

        case 3:

            t = Queue3.getHead();
            q3 = t->Next;
            Queue3.del();
            break;
        }
                processor(current, &procfree);
                
            }
            else if (q->priority < st->elem[st->top - 1][1]) {
                Node* temp = new Node;
                pop(st, temp);
                current = temp;
                processor(current, &procfree);
            }

            
        }

        else if (procfree && q == NULL && !stIsempty(st)) {
            Node *temp = new Node;
            pop(st, temp);
            current = temp;
            procfree = false;
        }

       
        

        cout << endl<<"Идет " << tact << " такт:" << endl;
        Queue1.qshow("первой");
        Queue2.qshow("второй");
        Queue3.qshow("третьей");
        procshow(current);
        if (!stIsempty(st)) stkPrint(st);

        tact++;
        qufree = isemp(Queue1, Queue2, Queue3);
        cout << endl;
    } while (!stIsempty(st) || !qufree || !procfree || countq!= numberOfTasks);
}