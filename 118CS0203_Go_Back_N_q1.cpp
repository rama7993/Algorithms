#include <bits/stdc++.h>
using namespace std;


int receiverAck,numberPacketsLost;
float percentageEff;
//No. of frames =10 and window size =4
int sender[10][4];
int SWPToSend = 0;
int SWPToReceive = 0;
int transmitTime/*Tt*/,globalTime = 0,generationTime/*Tp*/,timeOut;

void generate(int genTime,int packetNo)
{
    if(packetNo<11)cout<<"Packet number "<<packetNo<<" is generated at time = "<<genTime<<endl;

    sender[SWPToSend][0] = packetNo;
    sender[SWPToSend][1] = genTime;
    sender[SWPToSend][2] = 0;
    sender[SWPToSend][3] = 0;

    int randTemp = rand()%100;
    if(randTemp<numberPacketsLost)
    {
        if(packetNo<11)cout<<"This packet will be LOST in transit"<<endl<<endl;
        sender[SWPToSend][3] = genTime+timeOut;//Assume as corrupt
    }
    else
    {
        if(packetNo<11)cout<<"This packet will reach SAFELY"<<endl<<endl;
        sender[SWPToSend][2] = genTime+2*transmitTime;//Round Trip Time
    }

}

void goBack()
{
    for(int i = 0; i<10; i++)
    {
        for(int j = 0; j<4; j++)
        {
            sender[i][j] = 0;
        }
    }

    int packetNumber = 1;
    while(true)
    {
        bool timeOutOccr = false;
        if(sender[SWPToReceive][2]<=globalTime+generationTime&&sender[SWPToReceive][2]!=0)
        {
            cout<<"Packet Number "<<sender[SWPToReceive][0]<<" has been acknowledged at time = "<<sender[SWPToReceive][2]<<endl;
            if(sender[SWPToReceive][0]==10)break;
            SWPToReceive = (SWPToReceive+1)%10;

        }
        else if(sender[SWPToReceive][3]<=globalTime+generationTime&&sender[SWPToReceive][3]!=0)
        {
            cout<<"!!!Time out in packet number "<<sender[SWPToReceive][0]<<" has occurred at time = "<<sender[SWPToReceive][3]<<"!!!"<<endl;
            SWPToSend = SWPToReceive;
            packetNumber = sender[SWPToReceive][0];
            timeOutOccr = true;
        }

        globalTime = globalTime+generationTime;
        if(timeOutOccr)
        {
            globalTime = sender[SWPToReceive][3];
        }
        if(sender[SWPToReceive][0]==0)
        {
            generate(globalTime, packetNumber);
            packetNumber++;
            SWPToSend = (SWPToSend+1)%10;
        }
        else if(sender[(SWPToSend-1+10)%10][0]<11)
        {
            generate(globalTime, packetNumber);
            packetNumber++;
            SWPToSend = (SWPToSend+1)%10;
        }
    }
}

int main()
{
    cout<<"Enter the times for different network parameters:"<<endl;
    cout<<"Generation Time(Tp) (ms):";cin>>generationTime;
    cout<<"Transmission Time(Tt) (ms):";cin>>transmitTime;
    cout<<"TimeOut Time (ms):";cin>>timeOut;cout<<endl;
    cout<<"Enter The percentage efficiency:";cin>>percentageEff;
    numberPacketsLost = 100 -(int)percentageEff;
    cout<<"Assuming WINDOW SIZE =4 and NO. OF FRAMES=10";
    cout<<endl<<"Running Go back N"<<endl;
    for(int i = 0; i<30;i++)cout<<"_";
    cout<<endl<<endl;
    goBack();
    cin.get();
    return 0;
}
