#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
#include<string>

char b_name[1000][20], g_name[1000][20];
int breakup[1000][2];
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

void make_couples(vector <boy> &BOY, vector <girl> &GIRL )
{
	ofstream file;
    	file.open("log.txt",ios_base::app);
    	int i, j;
  	for(i=0; i<1000; i++)
    	{
    		for(j=0; j<1000; j++)
    		{
    			if(boy_commit[j] == 0 && girl_commit[i] == 0)
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
			    				break;
	    					} 
	    				}
	    			}
    			}
    		}
    	}
    	
}

int compatibility (vector <boy> &BOY, vector <girl> &GIRL)
{
	int i, j=0 , k=0, g, b;
	int vkc[1001]={0}, happy[1001]={0};
	for(i=0; i<1000; i++)
	{
		if(girl_commit[i] != 0)
		{
			b = girl_commit[i];
			g = i;
		    happy[k] = (BOY[b].budget - GIRL[g].maintain) + abs(BOY[b].attract - GIRL[g].attract) + abs(BOY[b].intellig - GIRL[g].intellig);
			vkc[k] = happy[k];
		//	cout<<" g "<<happy[k]<<endl;
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
				breakup[r][0] = g;
				breakup[r][1] = b;
				file<<GIRL[g].name<<" is " << r << " happy with "<<BOY[b].name <<" having happiness value "<<happy[j]<<endl;
				strcpy( b_name[r] , BOY[b].name);
				strcpy( g_name[r] , GIRL[g].name);
				r++;
				break;
			}
		}
	}
	return r;
}
void couples_after_breakup(vector <boy> &BOY, vector <girl> &GIRL,int k, int m)
{
	int i, j ,l, n, bx, yg, w;
	l = m-k;
	for(i=l; i<m; i++)
	{
		j = breakup[i][0];
		girl_commit[j] = 0;
		n = breakup[i][1];
		boy_commit[n] = 0;
	}
	
	ofstream file;
    	file.open("after_breakup_new_couples.txt",ios_base::app);
    	
    	for(i=l; i<m; i++)
    	{
    		yg = breakup[i][0];
    		for(j=0; j<1000; j++)
    		{
    			if(boy_commit[j] == 0 && girl_commit[yg] == 0)
    			{
	    			if(BOY[j].budget >= GIRL[yg].maintain)
	    			{
	    				if(GIRL[yg].attract > BOY[j].min_attract_g)
	    				{
	    					if(BOY[j].attract <= GIRL[yg].attract)
	    					{
		    					file << GIRL[yg].name <<" is going to make couple with " << BOY[j].name<<endl;
		    					girl_commit[yg] = j;
		    					boy_commit[j] = yg;
		    					break;
	    					} 
	    				}
	    			}
    			}
    		}
    		bx = breakup[i][1];
    		for(w=j; w<1000; w++)
    		{
    			if(girl_commit[w] == 0 && boy_commit[bx] == 0)
    			{
	    			if(BOY[bx].budget >= GIRL[w].maintain)
	    			{
	    				if(GIRL[w].attract > BOY[bx].min_attract_g)
	    				{
	    					if(BOY[bx].attract <= GIRL[w].attract)
	    					{
		    					file << GIRL[w].name <<" is going to make couple with " << BOY[bx].name<<endl;
		    					girl_commit[w] = bx;
		    					boy_commit[bx] = w;
		    					break;
	    					} 
	    				}
	    			}
    			}
    		}
    	}
}


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

void generate_gifts(int no_gifts){

    int price,value,i,lux,diff,utility_value;
    ofstream file;
    file.open("gifts_record.txt",ios_base::app);
    char type[25],type_of_gifts[][25] = {"Essential gift","Luxury gift","Utility gift"};
    char Class[] = "ABC",utility_class;
    for(i = 1;i <= no_gifts;i++){
        strcpy(type,type_of_gifts[rand()%3]);
        price = rand()%1000 + 1;
        value = rand()%10 + 1;
        file <<"gift -> " << i << endl;
        file << "type -> " << type << endl;
        file << "price -> " << price << endl;
        file << "value -> " << value << endl;

        if(type[0] == 'L'){
            lux = rand()%10 + 1;
            diff = rand()%10 + 1;
            file << "luxury : " << lux<< endl;
            file << "difficulty_for_gift :" << diff << endl;
        }
        else if(type[0] == 'U'){
            utility_value = rand()% 10 + 1;
            utility_class  = Class[rand()%3];
            file << "utility value : " << utility_value << endl;
            file << "utility class : " << utility_class << endl;
        }

        file << endl;
    }
    file.close();
}

int main()
{

vector <boy> BOY;
vector <girl> GIRL;

generate_gifts(1000);
generate_boys( BOY, 1000);
generate_girls( GIRL , 1000);
int m;
make_couples(BOY , GIRL);
m = compatibility(BOY, GIRL);
int k;
printf("give the number(k) of couples to breakup least happy\n"); 
scanf("%d",&k);
couples_after_breakup(BOY , GIRL ,k, m);

}






























