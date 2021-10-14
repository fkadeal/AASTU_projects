#include<graphics.h>
#include <iostream>
#include<string>
#include <sstream>
#include <cstring>
using namespace std;
 int main(void)
 {
    int gdriver=DETECT, gmode;
    int datasize,x,n,i,x1,x2,y1,y2; 
    char options;
 	initwindow(800,800);

 /* Initialize the variable */
  	x1 = 80,x2 = 50,y1 = 50,y2 = 600; 
     line(x1, y1, x1, y2+30);//y axis drawing 
	 line(30, y2, y2, y2);//x axis drawing
	 setfillstyle(SOLID_FILL,10);
 	cout<<"do you want to see sample data or enter data by your self ? (N | Y)"<<endl;
	cout<<"for manual input (Y) \n";
	cout<<"for sample data (N) recomended";
 	cin>>options;
 	 if (options == 'y' || options ==  'Y')  {
    	cout << "Enter the number(int) of items/data:" << "\n";
		cin >>datasize;
		datasize+=1;
    }else{
    	datasize=7+1;
    }
	int* arr = new int(datasize);
	int* temp = new int(datasize);
	int* temp2 = new int(datasize);
	string* u = new string[ datasize ];
	
	if (options == 'y' || options ==  'Y')  {
			cout << "Enter data title e.g: \"\"population\"\" " << "\n";
			cin>>u[datasize-1];
			const char *tstr =u[datasize-1].c_str();
		    char * title;
		    title = const_cast<char *>(tstr);
		   	settextstyle(1,HORIZ_DIR,1);
		    outtextxy(100,15, title);
		    	
			for (x = 0; x < datasize-1; x++) {
			cout << "Enter (" <<x<<"/"<<datasize << ") items name" << endl;cin>>u[x];
			cout << "Enter number value for \""<<u[x] <<"\" : "<< endl;cin >> arr[x];
			cout << "Ented "<<arr[x];
		}
	}else{
		
    u[0]="A.Ababa",u[1]="Afar",u[2]="Somali",u[3]="Dire Dawa",u[4]="Gambela",u[5]="Sidama",u[6]="Tigray";
    arr[0]=3434000,arr[1]=1812002,arr[2]=5748998,arr[3]=466000,arr[4]=435999,arr[5]=3200000,arr[6]=5247005;
    settextstyle(1,HORIZ_DIR,1);
    outtextxy(100,15, "some of ethiopian gegion population in 2017");
    settextstyle(200,HORIZ_DIR,10);
    outtextxy(130,35,"data-source from http://www.ethiovisit.com/ethiopia/ethiopia-regions-and-cities.html");
}
    
	double total=0;
	for(int i = 0; i < datasize-1; i++){
		total+=arr[i];
		cout <<"console.log(total ="<<total<<")"<<endl;
	}
	if(total > 1000){
	for(int i = 0; i < datasize-1; i++){
		temp[i]=arr[i]/total*600;
		cout <<"console.log(temp["<<i<<"]"<<"="<<temp[i]<<")"<<endl;
	}
	}else{
		for(int i = 0; i < datasize-1; i++){
		temp[i]=arr[i]/total*500;
		cout <<"console.log(temp["<<i<<"]"<<"="<<temp[i]<<")"<<endl;
	}
	}
	for(int i = 0; i < datasize-1; i++){
		temp2[i]=arr[i]/total*100;
		cout <<"console.log(temp["<<i<<"]"<<"="<<temp[i]<<")"<<endl;
	}
 for(x = 0; x < datasize-1; x++){
     const char *str =u[x].c_str();
     char * convline;
     convline = const_cast<char *>(str);
     cout<<"arr "<<arr[x]<<" i is "<<x<<"\n";
     settextstyle(8,VERT_DIR,1);
	 outtextxy(x1+25,600,convline);
	 settextstyle(200,HORIZ_DIR,10);
	 if(total <= 600) {
	 	y1 = y2-arr[x];
	  } else {
	 	y1 = y2-temp[x];
	 }
  	 
   	 x2=x1+40; 
   	 bar(x1,y1,x2,y2);
	 char buffer[16] = {0};
	 itoa(arr[x], buffer, 10);
	 outtextxy(30,y1-5, buffer);
	 char percent[16] = {0};
	 itoa(temp2[x], percent, 10);
	 outtextxy(x1+20,y1-15, percent);
	 outtextxy(x1+5,y1-15, "%");
	 x1=x1+50;
}

//""free up memory " if not clear the program may will case effect on next run //try it :)
	delete[] arr;
	delete[] temp;
	delete[] temp2;
	delete[] u;
 /* Close the Graph */
 getch();
    closegraph();
    return 0;
    }
    
