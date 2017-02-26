#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<string>

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

int make_couples(vector <boy> &BOY, vector <girl> &GIRL , int a[][2])
{
	ofstream file;
    	file.open("log.txt",ios_base::app);
    	
    	int i, j, l=0, k=0;
    	int commit[1000]={0};
    	for(i=0; i<1000; i++)
    	{
    		l=0;
    		for(j=0; j<1000; j++)
    		{
    			if(commit[j] == 0)
    			{
	    			if(BOY[j].budget >= GIRL[i].maintain)
	    			{
	    				if(GIRL[i].attract > BOY[j].min_attract_g)
	    				{
	    					if(BOY[j].attract <= GIRL[i].attract)
	    					{
		    		//	cout<<GIRL[i].name <<" is commited with "<<BOY[j].name <<"and both are having a happy valentine"<<endl;
		    			file << GIRL[i].name <<" is going to make couple with " << BOY[j].name<<endl;
		    				a[k][0] =i; a[k][1] = j;
		    				k++;
		    					commit[j] =1;
		    					l++;
		    					break;
	    					} 
	    				}
	    			}
    			}
    		}
    		if(l == 0)
    		{
    		//cout<<GIRL[i].name <<" is not going to make couple because her standard is too damn high "<<endl;
    		file << GIRL[i].name << "will always remain single because of high standard"<<endl;
    		} 		
    		
    	}
    	return k;
}

void compatibility (vector <boy> &BOY, vector <girl> &GIRL, int a[][2], int l)
{
	int i, j=0 , k, g, b;
	int compat[l];
	int vkc[l];
	for(i=0; i<l; i++)
	{
		g = a[i][0];
		b = a[i][1];
	      compat[i] = (BOY[b].budget - GIRL[g].maintain) + abs(BOY[b].attract - GIRL[g].attract) + abs(BOY[b].intellig - GIRL[g].intellig);
		//cout<<GIRL[g].name <<"  with  "<<BOY[b].name<<"  having compatibility  "<<compat[i]<<endl;
		vkc[i] = compat[i];
	}
	sort(compat, compat+l);
	ofstream file;
	file.open ("comapatible_couple.txt", ios_base::app);
	int r=1;
	for(i=l-1; i>=0; i--)
	{
		for(j=0; j<l; j++)
		{
			if(compat[i] == vkc[j])
			{
			g = a[j][0];
			b = a[j][1];
			file<<GIRL[g].name<<" has " << r++ << " compatibility with "<<BOY[b].name <<" value "<<compat[i]<<endl;
			break;
			}
		}
	}
	
}

int main()
{

vector <boy> BOY;
vector <girl> GIRL;

generate_gifts(1000);
generate_boys( BOY, 1000);
generate_girls( GIRL , 1000);

int a[1000][2] = {0};
int m;
m = make_couples(BOY , GIRL, a);
compatibility(BOY, GIRL, a, m);

}






























