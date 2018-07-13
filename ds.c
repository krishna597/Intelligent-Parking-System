#include<iostream>
#include<cstdlib>
#include<time.h>
#include<graphics.h>

using namespace std;

#define V 17
#define maxdis 20

class parking
{
    int g[V][V];
    char gate;
    int a[V];
public:
    parking()
    {
        parkingarea();
        setgate();
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                g[i][j]=maxdis;

        for(int i=1;i<V;i++)
                {
                    a[i]=rand()%2;
                    cout<<endl<<a[i];
                }
                /*a[2]=a[3]=a[4]=a[6]=a[7]=a[9]=a[11]=a[13]=a[14]=a[16]=0;
                for(int i=1;i<V;i++)
                {
                    if(a[i]!=0)
                        a[i]=1;
                    cout<<a[i]<<endl;
                }*/

        if(gate=='A')
        {
            g[0][1]=6;
            g[0][2]=1;
            g[0][3]=2;
            g[0][4]=7;
            g[0][5]=5;
            g[0][6]=2;
            g[0][7]=3;
            g[0][8]=6;
            g[0][9]=10;
            g[0][10]=4;
            g[0][11]=5;
            g[0][12]=11;
            g[0][13]=9;
            g[0][14]=6;
            g[0][15]=7;
            g[0][16]=10;
        }
        else
        {
            g[0][4]=6;
            g[0][3]=1;
            g[0][2]=2;
            g[0][1]=7;
            g[0][8]=5;
            g[0][7]=2;
            g[0][6]=3;
            g[0][5]=6;
            g[0][12]=10;
            g[0][11]=4;
            g[0][10]=5;
            g[0][9]=11;
            g[0][16]=9;
            g[0][15]=6;
            g[0][14]=7;
            g[0][13]=10;
        }
        int numofcar=0;
        for(int i=1;i<V;i++)
        {
            if(a[i]==1)
                {
                    if(i==1)
                    {
                        setcolor(WHITE);
                        car(50,65);
                        setcolor(RED);
                    }
                    else if(i==2)
                    {
                        setcolor(BLUE);
                        car(270/2,65);
                        setcolor(RED);
                    }
                    else if(i==3)
                    {
                        setcolor(BLUE);
                        car(415,65);
                        setcolor(RED);
                    }
                    else if(i==4)
                    {
                        setcolor(WHITE);
                        car(500,65);
                        setcolor(RED);
                    }
                    else if(i==5)
                    {
                        setcolor(GREEN);
                        car(50,265/2);
                        setcolor(RED);

                    }
                    else if(i==6)
                    {
                        setcolor(WHITE);
                        car(270/2,265/2);
                        setcolor(RED);
                    }
                    else if(i==7)
                    {
                        setcolor(GREEN);
                        car(415,265/2);
                        setcolor(RED);
                    }
                    else if(i==8)
                    {
                        setcolor(BLUE);
                        car(500,265/2);
                        setcolor(RED);
                    }
                    else if(i==9)
                    {
                        setcolor(BLUE);
                        car(50,265);
                        setcolor(RED);
                    }
                    else if(i==10)
                    {
                        setcolor(WHITE);
                        car(270/2,265);
                        setcolor(RED);
                    }
                    else if(i==11)
                    {
                        setcolor(BLUE);
                        car(415,265);
                        setcolor(RED);
                    }
                    else if(i==12)
                    {
                        setcolor(GREEN);
                        car(500,265);
                        setcolor(RED);
                    }
                    else if(i==13)
                    {
                        setcolor(GREEN);
                        car(50,665/2);
                        setcolor(RED);
                    }
                    else if(i==14)
                    {
                        setcolor(BLUE);
                        car(270/2,665/2);
                        setcolor(RED);
                    }
                    else if(i==15)
                    {
                        setcolor(WHITE);
                        car(415,665/2);
                        setcolor(RED);
                    }
                    else if(i==16)
                    {
                        setcolor(BLUE);
                        car(500,665/2);
                        setcolor(RED);
                    }
                    numofcar++;
                    g[0][i]=maxdis;
                }
        }
        cout<<endl<<numofcar<<" cars are there in the parking region."<<endl;
        dijkstra(g, 0);
    }
    void setgate()
    {
        setcolor(YELLOW);
        srand(time(NULL));
        if((rand()%2==1))
        {
            gate='A';
            outtextxy(7,7,"You are at gate A");
        }
        else
        {
            gate='B';
            outtextxy(7,10,"You are at gate B");
        }
        outtextxy(400,10,"Park where yellow car is blinking");
        setcolor(GREEN);
        cout<<"You are at gate "<<gate<<" now"<<endl;
    }


    int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = maxdis, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
   cout<<"Vertex   Distance from Source\n";
   for (int i = 0; i < V; i++)
            cout<<i<<'\t'<<'\t'<<dist[i]<<endl;
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int [V][V], int src)
{
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i

     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = maxdis , sptSet[i] = false;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;

     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < V; v++)

         // Update dist[v] only if is not in sptSet, there is an edge from
         // u to v, and total weight of path from src to  v through u is
         // smaller than current value of dist[v]
         if (!sptSet[v] && g[u][v] && dist[u] != INT_MAX
                                       && dist[u]+g[u][v] < dist[v])
            dist[v] = dist[u] + g[u][v];
     }

     // print the constructed distance array
     printSolution(dist, V);
     findshortestpath(dist);
}
        void findshortestpath(int dist[])
        {
            int minimumdis=dist[1] ,i;
            for(i=2;i<V;i++)
            {
                if(dist[i]<minimumdis)
                    minimumdis=dist[i];
            }
            for(i=1;i<V;i++)
            {
                if(dist[i]==minimumdis)
                    break;
            }
            a[i]=1;
            cout<<endl<<"You have to park your vehicle at slot number "<<i<<"."<<endl;
            bookspace(i);
        }
    void bookspace(int j)
    {
        for(int i=1;i<V;i++)
        {
            if(j==i)
                {for(;;){
                    if(i==1)
                    {
                        setcolor(YELLOW);
                        car(50,65);
                        delay(1000);
                        setcolor(BLACK);
                        car(50,65);
                        delay(1000);
                    }
                    else if(i==2)
                    {
                        setcolor(YELLOW);
                        car(270/2,65);
                        delay(1000);
                        setcolor(BLACK);
                        car(270/2,65);
                        delay(1000);
                    }
                    else if(i==3)
                    {
                        setcolor(YELLOW);
                        car(415,65);
                        delay(1000);
                        setcolor(BLACK);
                        car(415,65);
                        delay(1000);
                    }
                    else if(i==4)
                    {
                        setcolor(YELLOW);
                        car(500,65);
                        delay(1000);
                        setcolor(BLACK);
                        car(500,65);
                        delay(1000);
                    }
                    else if(i==5)
                    {
                        setcolor(YELLOW);
                        car(50,265/2);
                        delay(1000);
                        setcolor(BLACK);
                        car(50,265/2);
                        delay(1000);

                    }
                    else if(i==6)
                    {
                        setcolor(YELLOW);
                        car(270/2,265/2);
                        delay(1000);
                        setcolor(BLACK);
                        car(270/2,265/2);
                        delay(1000);
                    }
                    else if(i==7)
                    {
                        setcolor(YELLOW);
                        car(415,265/2);
                        delay(1000);
                        setcolor(BLACK);
                        car(415,265/2);
                        delay(1000);
                    }
                    else if(i==8)
                    {
                        setcolor(YELLOW);
                        car(500,265/2);
                        delay(1000);
                        setcolor(BLACK);
                        car(500,265/2);
                        delay(1000);
                    }
                    else if(i==9)
                    {
                        setcolor(YELLOW);
                        car(50,265);
                        delay(1000);
                        setcolor(BLACK);
                        car(50,265);
                        delay(1000);
                    }
                    else if(i==10)
                    {
                        setcolor(YELLOW);
                        car(270/2,265);
                        delay(1000);
                        setcolor(BLACK);
                        car(270/2,265);
                        delay(1000);
                    }
                    else if(i==11)
                    {
                        setcolor(YELLOW);
                        car(415,265);
                        delay(1000);
                        setcolor(BLACK);
                        car(415,265);
                        delay(1000);
                    }
                    else if(i==12)
                    {
                        setcolor(YELLOW);
                        car(500,265);
                        delay(1000);
                        setcolor(BLACK);
                        car(500,265);
                        delay(1000);
                    }
                    else if(i==13)
                    {
                        setcolor(YELLOW);
                        car(50,665/2);
                        delay(1000);
                        setcolor(BLACK);
                        car(50,665/2);
                        delay(1000);
                    }
                    else if(i==14)
                    {
                        setcolor(YELLOW);
                        car(270/2,665/2);
                        delay(1000);
                        setcolor(BLACK);
                        car(270/2,665/2);
                        delay(1000);
                    }
                    else if(i==15)
                    {
                        setcolor(YELLOW);
                        car(415,665/2);
                        delay(1000);
                        setcolor(BLACK);
                        car(415,665/2);
                        delay(1000);
                    }
                    else if(i==16)
                    {
                        setcolor(YELLOW);
                        car(500,665/2);
                        delay(1000);
                        setcolor(BLACK);
                        car(500,665/2);
                        delay(1000);
                    }}
                    setcolor(RED);
                }
            }
    }

    void parkingarea()
    {
        setcolor(RED);
        line(0,0,0,getmaxy());
        line(1+1,1+1,1+1,getmaxy()-1-1);
        line(0,0,getmaxx(),0);
        line(1+1,1+1,getmaxx()-1-1,1+1);
        line(0,getmaxy(),getmaxx(),getmaxy());
        line(1+1,getmaxy()-1-1,getmaxx()-1-1,getmaxy()-1-1);
        line(getmaxx(),0,getmaxx(),getmaxy());
        line(getmaxx()-1-1,1+1,getmaxx()-1-1,getmaxy()-1-1);
        line(4,4,4,getmaxy()-4);
        line(1+1+4,1+1+4,1+1+4,getmaxy()-1-1-4);
        line(4,4,getmaxx()-4,4);
        line(1+1+4,1+1+4,getmaxx()-1-1-4,1+1+4);
        line(4,getmaxy()-4,getmaxx()-4,getmaxy()-4);
        line(1+1+4,getmaxy()-1-1-4,getmaxx()-1-1-4,getmaxy()-1-1-4);
        line(getmaxx()-4,4,getmaxx()-4,getmaxy()-4);
        line(getmaxx()-1-1-4,1+1+4,getmaxx()-1-1-4,getmaxy()-1-1-4);
        rectangle(getmaxx()/2-50,6,getmaxx()/2+50,getmaxy()-6);
        line(getmaxx()/2,6,getmaxx()/2,getmaxy()-6);
        line(0+6,40,getmaxx()-6,40);
        line(0+6,getmaxy()-40,getmaxx()-6,getmaxy()-40);
        rectangle(50,65,220,200);

        line(270/2,65,270/2,200);

        line(50,265/2,220,265/2);

        rectangle(415,65,585,200);

        line(500,65,500,200);

        line(415,265/2,585,265/2);


        rectangle(50,265,220,400);
        line(270/2,265,270/2,400);
        line(50,665/2,220,665/2);
        rectangle(415,265,585,400);
        line(500,265,500,400);
        line(415,665/2,585,665/2);

        rectangle(getmaxx()/2-30,55,getmaxx()/2-20,85);
        int p[]={getmaxx()/2-35,85,getmaxx()/2-15,85,getmaxx()/2-25,100,getmaxx()/2-35,85};
        drawpoly(4,p);

        rectangle(getmaxx()/2-30,155,getmaxx()/2-20,185);
        int q[]={getmaxx()/2-35,185,getmaxx()/2-15,185,getmaxx()/2-25,200,getmaxx()/2-35,185};
        drawpoly(4,q);

        rectangle(getmaxx()/2-30,305,getmaxx()/2-20,335);
        int r[]={getmaxx()/2-35,335,getmaxx()/2-15,335,getmaxx()/2-25,350,getmaxx()/2-35,335};
        drawpoly(4,r);

        rectangle(getmaxx()/2+30,55,getmaxx()/2+20,85);
        int s[]={getmaxx()/2+35,85,getmaxx()/2+15,85,getmaxx()/2+25,100,getmaxx()/2+35,85};
        drawpoly(4,s);

        rectangle(getmaxx()/2+30,155,getmaxx()/2+20,185);
        int t[]={getmaxx()/2+35,185,getmaxx()/2+15,185,getmaxx()/2+25,200,getmaxx()/2+35,185};
        drawpoly(4,t);

        rectangle(getmaxx()/2+30,305,getmaxx()/2+20,335);
        int u[]={getmaxx()/2+35,335,getmaxx()/2+15,335,getmaxx()/2+25,350,getmaxx()/2+35,335};
        drawpoly(4,u);

        rectangle(20,205,30,235);
        int v[]={15,205,35,205,25,190,15,205};
        drawpoly(4,v);

        rectangle(getmaxx()-20,205,getmaxx()-30,235);
        int w[]={getmaxx()-15,205,getmaxx()-35,205,getmaxx()-25,190,getmaxx()-15,205};
        drawpoly(4,w);

        rectangle(120,225,170,237);
        int vp[]={120,218,120,244,105,462/2,120,218};
        drawpoly(4,vp);

        rectangle(getmaxx()-120,225,getmaxx()-170,237);
        int vq[]={getmaxx()-120,218,getmaxx()-120,244,getmaxx()-105,462/2,getmaxx()-120,218};
        drawpoly(4,vq);

        rectangle(120,getmaxy()-25-30,170,getmaxy()-37-30);
        int vr[]={120,getmaxy()-18-30,120,getmaxy()-44-30,105,getmaxy()-31-30,120,getmaxy()-18-30};
        drawpoly(4,vr);

        rectangle(getmaxx()-120,getmaxy()-25-30,getmaxx()-170,getmaxy()-37-30);
        int vs[]={getmaxx()-120,getmaxy()-18-30,getmaxx()-120,getmaxy()-44-30,getmaxx()-105,getmaxy()-31-30,getmaxx()-120,getmaxy()-18-30};
        drawpoly(4,vs);

        setcolor(GREEN);
        outtextxy(getmaxx()/2-48,18,"Gate A");
        outtextxy(getmaxx()/2+3,18,"Gate B");


    }
    void car(int x,int y)
    {
        rectangle(x+10+5,y+10,x+60+5,y+50+5);
        arc(x+10+55/2,y+10+45/2+1,-38,38,37);
        arc(x+10+55/2,y+10+45/2+1,180-42,180+42,32);
        //setcolor(YELLOW);
        rectangle(x+10+5+10,y+10+10,x+60+5-20,y+50+5-10);
    }


};

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\TG\\BGI");

    parking p;

    getch();
    closegraph();

}

