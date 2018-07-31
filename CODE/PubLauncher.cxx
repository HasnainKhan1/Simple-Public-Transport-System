#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include <string>
#include <pthread.h>
#include <iostream>
#include <ctime>
#include <sys/types.h>
#include <sstream>
#include <cstdlib>


//change int to string
#define SSTR(x) dynamic_cast< std::ostringstream & >((std::ostringstream() << std::dec << x )).str()

using namespace std;

struct bus_properties{
    int routenumStops;
    int routeTimeBetweenStops;
    char routename[10];
    char bus_name[6];
    int status;  //indicate bus status
    int ratio;
    int location; //number of stop
    //int numInitialBackupVehicles;
    //char backupcar[5][6];
    int numRoutes;

};
int getValue(char *input, char *output);
void clearbuffer(char *fline, char *fvalue);
char *traffic[4]={"heavy","light","normal","normal"}; //heavy=25%  light=25%  normal=50%
double accidentP=0.1;  //possibility of accident

void *bus(void *thread)
{
    int i;

    struct bus_properties *thisbus=(struct bus_properties *)thread;

    string argument_pos;
    //arguments send to position_publisher
    argument_pos = "./objs/x64Linux3gcc5.4.0/position_publisher";
    argument_pos.append(thisbus->routename).append(" ").append(thisbus->bus_name).append(" ").append(SSTR(thisbus->routenumStops)).append(" ").append(SSTR(thisbus->routeTimeBetweenStops)).append(" ").append(SSTR(accidentP)).append(" ").append(SSTR(thisbus->numRoutes));
    //cout << argument_pos << endl;
    system(argument_pos.c_str());
    return 0;
}


int main (int argc, char *argv[])
{
    int i,j,k,m;
    int numRoutes;
    int numVehicles;

    //parse from file
    FILE * pFile;
    char fline[80], fvalue[10];
    pFile = fopen ("pub.properties","r");


    fgets(fline,80, pFile);
    //numRoutes
    fgets(fline,80, pFile);
    getValue(fline, fvalue);
    numRoutes = atoi(fvalue);
    //numVehicles
    clearbuffer(fline,fvalue);
    fgets(fline,80, pFile);
    getValue(fline, fvalue);
    numVehicles = atoi(fvalue);

    //routename
    char routename[numRoutes][10];
    for (i=0;i<numRoutes;i++)
    {
        clearbuffer(fline,fvalue);
        fgets(fline,80, pFile);
        getValue(fline, fvalue);
        strcpy(routename[i],fvalue );
    }
    //start for each route
    int route1numStops[numRoutes];
    int route1TimeBetweenStops[numRoutes];
    char busname[numRoutes][numVehicles][5];

    for(i=0;i<numRoutes;i++)
    {
        fgets(fline,80, pFile);
        //route1numStops
        clearbuffer(fline,fvalue);
        fgets(fline,80, pFile);
        getValue(fline, fvalue);
        route1numStops[i]=atoi(fvalue);
        //route1TimeBetweenStops
        clearbuffer(fline,fvalue);
        fgets(fline,80, pFile);
        getValue(fline, fvalue);
        route1TimeBetweenStops[i]=atoi(fvalue);
        //busname
        for(j=0; j<numVehicles;j++)
        {
            clearbuffer(fline,fvalue);
            fgets(fline,80, pFile);
            getValue(fline, fvalue);
            strcpy(busname[i][j],fvalue );
        }

    }
    fclose (pFile);



    //craete thread
    struct bus_properties eachbus[numRoutes*numVehicles];
    int NUM_THREADS = numRoutes*numVehicles;
    pthread_t threads[NUM_THREADS];

    for (i=0;i<numRoutes;i++)
    {
        for(j=0; j<numVehicles;j++)
        {
            eachbus[(i*numVehicles)+j].routenumStops=route1numStops[i];
            eachbus[(i*numVehicles)+j].routeTimeBetweenStops=route1TimeBetweenStops[i];
            eachbus[(i*numVehicles)+j].numRoutes = numRoutes;
            strcpy(eachbus[(i*numVehicles)+j].routename,routename[i]);

            for(k=0;k<5;k++)
            {
                eachbus[(i*numVehicles)+j].bus_name[k]=busname[i][j][k];
            }

        }
    }
    for (i=0;i<numRoutes;i++)
    {
        for(j=0; j<numVehicles;j++)
        {
            printf("Thread %s started\n", eachbus[(i*numVehicles)+j].bus_name);
            pthread_create(&threads[(i*numVehicles)+j], NULL, bus, &eachbus[(i*numVehicles)+j]);
            //pthread_create(threads +(i*numVehicles)+j, NULL, bus, &eachbus[(i*numVehicles)+j]);
        }
    }


    printf("All buses have started. Waiting for them to terminate...\n");
    /* wait for all threads to complete */
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }


    return 0;
}

int getValue(char *input, char *output)
{
    int i, mark, valueStart,setmark;

    //scan for mark '#'
    setmark = 0; //0 = no mark, 1= has mark
    for(i=0;i<strlen(input);i++)
    {
        if(input[i]=='#')
        {
            setmark=1;
            break;
        }

    }
    mark=i;

    //search for =
    for(i=0;i<mark;i++)
    {
        if(input[i]=='=')
            break;
    }

    if(i==mark)  //not a parameter
        return 1;
    else
    {
        if(setmark==0)
            mark = mark-1; //eliminate \n and \r
        i=i+1;
        //skip space
        while(input[i]==' ')
            i++;
        valueStart = i;
    }
    for(i=valueStart;i<mark;i++)
    {
        if(input[i]==' ')
            break;
        output[i-valueStart]=input[i];
    }
    return 0;
}

void clearbuffer(char *fline, char *fvalue)
{
    int i;
        for(i=0;i<strlen(fline);i++)
        {
            fline[i]='\0';
        }
        for(i=0;i<10;i++)
        {
            fvalue[i]='\0';
        }
}
