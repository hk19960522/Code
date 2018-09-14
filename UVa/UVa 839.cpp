  #include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Node
{
    Node *Left;
    Node *Right;
    Node *Up;
    int LW, LL, RW, RL;
};

void Init ( Node * x )
{
    x->Left = NULL;
    x->Right = NULL;
    x->Up = NULL;
    x->LW = 0;
    x->LL = 0;
    x->RW = 0;
    x->RL = 0;
}

Node * Write ( Node * now , int lw , int ll , int rw , int rl )
{
    if ( now->LL )
    {
        if ( now->LW == 0 && now->Left == NULL )
        {
            Node * temp = ( Node * )malloc( sizeof(Node) );
            Init( temp );
            temp->LL = ll;
            temp->LW = lw;
            temp->RL = rl;
            temp->RW = rw;
            temp->Up = now;
            now->Left = temp;
            return temp;
        }
        else if ( now->RW == 0 && now->Right == NULL )
        {
            Node * temp = ( Node * )malloc( sizeof(Node) );
            Init( temp );
            temp->LL = ll;
            temp->LW = lw;
            temp->RL = rl;
            temp->RW = rw;
            temp->Up = now;
            now->Right = temp;
            return temp;
        }
        else
        {
            now = now->Up;
            return Write( now , lw , ll , rw , rl );
        }
    }
    else
    {
        now->LL = ll;
        now->LW = lw;
        now->RL = rl;
        now->RW = rw;
        return now;
    }
}

void Print ( Node * now )
{
    cout << now->LL << " " << now->LW << " "<< now->RL << " " << now->RW << endl;
    if ( now->Left )
        cout << "Left : \n" , Print(now->Left);
    if ( now->Right )
        cout << "Right : \n" , Print(now->Right);
    cout << "Back \n";
}

int ADD ( Node * now )
{
    if ( now->LW == 0  && now->Left )
        now->LW = ADD( now->Left );
    if ( now->RW == 0 && now->Right )
        now->RW = ADD( now->Right );
    return now->LW + now->RW ;
}

bool Check ( Node * now , bool D )
{
    if ( now->Left )
        D = D && Check( now->Left , D );
    if ( now->Right )
        D = D && Check( now->Right , D );

    if ( ( now->LL * now->LW ) == ( now->RL * now->RW ) )
        return D && true;
    else
        return false;
}

int main()
{
    int T;
    scanf("%d ",&T);

    while ( T-- )
    {
        string in;
        Node * Head;
        Node * Now;

        Head = ( Node * )malloc( sizeof(Node) );
        Init( Head );
        Now = Head;
        while ( getline( cin , in ) && in != "" )
        {
            stringstream ss;
            ss << in;

            int lw,ll,rw,rl;
            ss >> lw >> ll >> rw >> rl;
            Now = Write( Now , lw , ll , rw , rl );
        }
        Now = Head;
        ADD(Now);
        Now = Head;

        bool Result = 1;
        Result = Check( Now , true );
        if ( Result )
            cout << "YES\n";
        else
            cout << "NO\n";
        if ( T )
            cout << endl;
    }
    return 0;
}
