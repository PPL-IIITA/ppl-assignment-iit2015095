#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
#include<string>

int boy_commit[1000]={0};
int girl_commit[1000]={0};
class boy{

public:

	char name[10];
	int attract;
	int intellig;
	int budget;
	int min_attract_g;
	int b;
	char committed_boys_types[15];
};

class girl{

public:

	char name[10];
	int attract;
	int intellig;
	int maintain;
	int gift;
	int g;
	char committed_girls_type[15];
};

void generate_boys(vector <boy> &BOY , int n)
{
	ofstream file;
	file.open("boys_records.txt",ios_base::app);
	char str[] = "abcdefghijklmnopqrstuvwxyz";
	int i, j ,k , l,m;
	char committed_boys_types[15];
	int attract, intellig, budget, min_attract_g, b_gift;
	char type[][50] = {"The Miser","The Generous","The Geeks"};
	for(i=0; i<n; i++)
	{
		char name[10];
		for(j=0; j<10; j++)
		{
			name[j] = str[(rand()%25)];
		}
		name[j] ='\0';
		strcpy(committed_boys_types,type[rand()%3]);
		
		attract = rand()%10;
		intellig = rand()%20;
		budget = rand()%50000;
		min_attract_g = rand()%10;
		b_gift = rand()%20;
		
		file << "name -> " <<name;
		file << "attractiveness of boy-> " << attract << "\t";
		file << "intelligence of boy-> " << intellig <<"\t";
		file << "budget of boy-> " << budget <<"\t";
		file << "min_attraction_of_girl -> " << min_attract_g <<"\t";
		file << "type_of_committed_boy -> " << committed_boys_types <<"\t";
		file << endl;
		
		boy New;
		strcpy(New.name , name);
		New.attract = attract;
		New.intellig = intellig;
		New.budget = budget;
		New.min_attract_g = min_attract_g;
		strcpy(New.committed_boys_types , committed_boys_types);
		New.b = 0;
       		BOY.push_back(New);
	
	}
	file.close();
}

void generate_girls( vector <girl> &GIRL , int n)
{
	ofstream file;
	file.open("girls_records.txt",ios_base::app);
	char str[] = "abcdefghijklmnopqrstuvwxyz";
	int i, j ,k , l,m;
	char committed_girls_type[15];
	int attract, intellig, maintain, gift;
	char type[][50] = {"The Miser","The Generous","The Geeks"};
	for(i=0; i<n; i++)
	{
		char name[10];
		for(j=0; j<10; j++)
		{
			name[j] = str[(rand()%25)];
		}
		name[j] ='\0';
		strcpy(committed_girls_type,type[rand()%3]);
		
		attract = rand()%10;
		intellig = rand()%20;
		maintain = rand()%50000;
		gift = rand()%20;
		
		file << "name -> " <<name <<"\t";
		file << "gift by boy -> " <<gift <<"\t";
		file << "attractiveness of girl -> " << attract<<"\t" ;
		file << "intelligence of girl-> " << intellig <<"\t";
		file << "maintenance of girl-> " << maintain <<"\t";
		file << "committed_girls_type -> " << committed_girls_type <<"\t";
		file << endl;
	
		girl New;
		strcpy(New.name , name);
		New.attract = attract;
		New.intellig = intellig;
		New.maintain = maintain;
		New.gift = gift;
		New.g = 0;
		strcpy(New.committed_girls_type , committed_girls_type);
        	GIRL.push_back(New);
	}
	file.close();
}


void make_couples(vector <boy> &BOY, vector <girl> &GIRL )
{
	ofstream file;
    	file.open("log.txt",ios_base::app);
    	int i, j, l=0, k=0, m ,n;
    	int y=1;
    	i=0; m=0;
    	while(y++ <=1000)
    	{
    		if(y%2 == 1)
    		{
		    		l=0;
		    		for(j=0; j<1000; j++)
		    		{
		    			if(girl_commit[i] == 0 && boy_commit[j] == 0)
		    			{
			    			if(BOY[j].budget >= GIRL[i].maintain)
			    			{
			    				if(GIRL[i].attract > BOY[j].min_attract_g)
			    				{
			    					if(BOY[j].attract <= GIRL[i].attract)
			    					{
				    				file << GIRL[i].name <<" is going to make couple with " << BOY[j].name<<endl;
				    					boy_commit[j] = i;
				    					girl_commit[i] = j;
				    					l++;
				    					break;
			    					} 
			    				}
			    			}
		    			}
		    		}
		    		if(l == 0)
		    		{
		    		file << GIRL[i].name << " SINGLE GIRL because of EGO "<<endl;
		    		} 
		    	i++;		
	    	}
	    	else
	    	{
		    		l=0;
		    		for(n=0; n<1000; n++)
		    		{
		    			if(boy_commit[m] == 0 && girl_commit[n] == 0)
		    			{
			    			if(BOY[m].budget >= GIRL[n].maintain)
			    			{
			    				if(GIRL[n].attract > BOY[m].min_attract_g)
			    				{
			    					if(BOY[m].attract <= GIRL[n].attract)
			    					{
				    				file << GIRL[n].name <<" is going to make couple with " << BOY[m].name<<endl;

				    					boy_commit[m] = n;
				    					girl_commit[n] = m;
				    					l++;
				    					break;
			    					} 
			    				}
			    			}
		    			}
		    		}
		    		if(l == 0)
		    		{
		    		file << BOY[m].name << " as usual SINGLE BOY"<<endl;
		    		} 		
		    		
		    	m++;
	    	}
	    	
    	}
    	
}

void compatibility (vector <boy> &BOY, vector <girl> &GIRL)
{
	int i, j=0 , k=0, g, b;
	int vkc[1001]={0}, happy[1001]={0};
	for(i=0; i<1000; i++)
	{
		if(boy_commit[i] != 0 && girl_commit[i] != 0)
		{
			g = boy_commit[i];
			b = i;
		    happy[k] = (BOY[b].budget - GIRL[g].maintain) + abs(BOY[b].attract - GIRL[g].attract) + abs(BOY[b].intellig - GIRL[g].intellig);
			vkc[k] = happy[k];
		//	cout<<" b "<<happy[k]<<endl;
			k++;
		}
	}
	sort(vkc, vkc+k);
	ofstream file;
	file.open ("happiest_couple.txt", ios_base::app);
	int r=1;
	for(i=k-1; i>=0; i--)
	{
		for(j=0; j<k; j++)
		{
			if(happy[j] == vkc[i])
			{
				g = boy_commit[j];
				b = j;
				file<<GIRL[g].name<<" is " << r++ << " happy with "<<BOY[b].name <<" having happiness value "<<happy[j]<<endl;
				break;
			}
		}
	}
	
}

int main()
{

vector <boy> BOY;
vector <girl> GIRL;

generate_boys( BOY, 1000);
generate_girls( GIRL , 1000);
make_couples(BOY , GIRL);
compatibility(BOY, GIRL);
cout<<"completed task"<<endl;
}






























