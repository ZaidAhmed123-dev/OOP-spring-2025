#include<iostream>
using namespace std;

class markerPen{
    
    public:
    string brand;
    string color;
    int inkLevel=10;
    int refillability=1;
    
        void write()
        {
            inkLevel--;
            refillability=0;
            cout<<"ink level decreased to: "<<inkLevel<<endl;
        }

        void refill()
        {
            if(inkLevel<10)
            {
                inkLevel=10;
                refillability=1;
                cout<<"successfully refilled!\n";
            }
        }
};

int main()
{
    markerPen P[3];

    for(int i=0;i<3;i++)
    {
        cout<<"enter brand for pen "<<i+1<<": ";cin>>P[i].brand;
        cout<<"enter color for pen "<<i+1<<": ";cin>>P[i].color;
    }

    while(1)
    {
        int op,a;
        cout<<"choose an option\n1. write\n2. refill\n3. check status\n4. exit\n";
        cin>>op;
        cout<<"enter pen index to apply to: ";
        cin>>a;
        a=a-1;
        switch(op)
        {
            case 1:
                P[a].write();
                break;
            case 2:
                P[a].refill();
                break;
            case 3:
                cout<<"brand: "<<P[a].brand<<endl;
                cout<<"color: "<<P[a].color<<endl;
                cout<<"ink level: "<<P[a].inkLevel<<endl;
                cout<<"refillability: ";
                if(P[a].refillability)
                {
                    cout<<"cannot refill."<<endl;
                }
                else
                    cout<<"can refill."<<endl;

                break;
            case 4:
                return 0;
        }
    }
    return 0;
}

