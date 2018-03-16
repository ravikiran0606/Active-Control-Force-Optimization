#include<bits/stdc++.h>

using namespace std;

struct beam{
	int bno;
	double pd,md,n,k,ratio,p;

	beam(){
    	bno=-1;
    	pd=0;
    	md=0;
    	ratio=0;
    	n=0;
    	k=0;
    	p=0;
	}

	beam(int bno,double pd,double md){
		bno=bno;
		pd=pd;
		md=md;
	}
};

struct pnode{
	double mini[5],maxi[5];
	double mymini[5],mymaxi[5];
	double mzmini[5],mzmaxi[5];

	pnode(){
		for(int i=0;i<=4;i++){
			mini[i]=maxi[i]=0;
			mymini[i]=mymaxi[i]=0;
			mzmini[i]=mzmaxi[i]=0;
		}
	}
};

map<int,beam>beams;
map<int,int>bmap;
map<int,pnode>pval;
vector< vector<int> > comb;
set< vector<double> > lst;
set< vector<double> >:: iterator it;
double irange[10],myrange[10],mzrange[10];
int nodalpt[10];
int beamno[10];
long long itno;

void init(){

	// creating beam members...

	beam b;
	b.bno = 60;
	b.pd = 244.55;
	b.md = 29.09;
	beams[60]=b;

	b.bno = 62;
	beams[62]=b;

	b.bno = 52;
	beams[52]=b;

	b.bno = 51;
	beams[51]=b;

	b.bno = 58;
	beams[58]=b;

	// mapping beam numbers...

	bmap[60]=0;
	bmap[62]=1;
	bmap[52]=2;
	bmap[51]=3;
	bmap[58]=4;

	beamno[0]=60;
	beamno[1]=62;
	beamno[2]=52;
	beamno[3]=51;
	beamno[4]=58;

	// assigning nodal points...

	nodalpt[0]=6;
	nodalpt[1]=7;
	nodalpt[2]=44;
	nodalpt[3]=43;
	nodalpt[4]=36;
	nodalpt[5]=35;

	// assigning the interpolate range values...

	irange[1] = 1;
	irange[2] = 2.0134;
	irange[3] = 3.036;
	irange[4] = 4.068;
	irange[5] = 5.112;
	irange[6] = 6.1521;

	myrange[1] = 1;
	myrange[2] = 2.0175;
	myrange[3] = 3.0439;
	myrange[4] = 4.0756;
	myrange[5] = 5.1041;
	myrange[6] = 6.0117;

	mzrange[1] = 1;
	mzrange[2] = 2.0184;
	mzrange[3] = 3.0339;
	mzrange[4] = 4.2475;
	mzrange[5] = 5.1252;
	mzrange[6] = 6.4361;


	// pvalue for nodal points...

	pnode p;

	// point 0 p values

	p.mini[0] = 232.14;
	p.maxi[0] = 230.44;
	p.mini[1] = 232.14;
	p.maxi[1] = 230.76;
	p.mini[2] = 175.74;
	p.maxi[2] = 174.84;
	p.mini[3] = 175.74;
	p.maxi[3] = 174.84;
	p.mini[4] = 197.32;
	p.maxi[4] = 199.02;

	// point 0 my values

	p.mymini[0] = 0.1552;
	p.mymaxi[0] = 0.1543;
	p.mymini[1] = 0.1552;
	p.mymaxi[1] = 0.1537;
	p.mymini[2] = 0.1526;
	p.mymaxi[2] = 0.1519;
	p.mymini[3] = 0.1526;
	p.mymaxi[3] = 0.1507;
	p.mymini[4] = 0.1318;
	p.mymaxi[4] = 0.1309;

	// point 0 mz values

	p.mzmini[0] = 1.0781;
	p.mzmaxi[0] = 1.0699;
	p.mzmini[1] = 1.0781;
	p.mzmaxi[1] = 1.0717;
	p.mzmini[2] = 1.2583;
	p.mzmaxi[2] = 1.2511;
	p.mzmini[3] = 1.2583;
	p.mzmaxi[3] = 1.2520;
	p.mzmini[4] = 0.9163;
	p.mzmaxi[4] = 0.9245;

	pval[6]=p;

	// point 1 p values

	p.mini[0] = 232.14;
	p.maxi[0] = 230.76;
	p.mini[1] = 232.14;
	p.maxi[1] = 230.44;
	p.mini[2] = 175.74;
	p.maxi[2] = 174.76;
	p.mini[3] = 175.74;
	p.maxi[3] = 174.84;
	p.mini[4] = 197.32;
	p.maxi[4] = 198.70;

	// point 1 my values

	p.mymini[0] = 0.1552;
	p.mymaxi[0] = 0.1537;
	p.mymini[1] = 0.1552;
	p.mymaxi[1] = 0.1543;
	p.mymini[2] = 0.1526;
	p.mymaxi[2] = 0.1507;
	p.mymini[3] = 0.1526;
	p.mymaxi[3] = 0.1519;
	p.mymini[4] = 0.1318;
	p.mymaxi[4] = 0.1304;

	// point 1 mz values

	p.mzmini[0] = 1.0781;
	p.mzmaxi[0] = 1.0717;
	p.mzmini[1] = 1.0781;
	p.mzmaxi[1] = 1.0699;
	p.mzmini[2] = 1.2583;
	p.mzmaxi[2] = 1.2520;
	p.mzmini[3] = 1.2583;
	p.mzmaxi[3] = 1.2511;
	p.mzmini[4] = 0.9163;
	p.mzmaxi[4] = 0.9227;

	pval[7]=p;

	// point 2 p values

	p.mini[0] = 232.14;
	p.maxi[0] = 231.28;
	p.mini[1] = 232.14;
	p.maxi[1] = 230.80;
	p.mini[2] = 175.74;
	p.maxi[2] = 175.42;
	p.mini[3] = 175.74;
	p.maxi[3] = 175.46;
	p.mini[4] = 197.32;
	p.maxi[4] = 198.19;

	// point 2 my values

	p.mymini[0] = 0.1552;
	p.mymaxi[0] = 0.1540;
	p.mymini[1] = 0.1552;
	p.mymaxi[1] = 0.1547;
	p.mymini[2] = 0.1526;
	p.mymaxi[2] = 0.1540;
	p.mymini[3] = 0.1526;
	p.mymaxi[3] = 0.1520;
	p.mymini[4] = 0.1318;
	p.mymaxi[4] = 0.1307;

	// point 2 mz values

	p.mzmini[0] = 1.0781;
	p.mzmaxi[0] = 1.0742;
	p.mzmini[1] = 1.0781;
	p.mzmaxi[1] = 1.0715;
	p.mzmini[2] = 1.2583;
	p.mzmaxi[2] = 1.0742;
	p.mzmini[3] = 1.2583;
	p.mzmaxi[3] = 1.2537;
	p.mzmini[4] = 0.9163;
	p.mzmaxi[4] = 0.9202;

	pval[44]=p;

	// point 3 p values

	p.mini[0] = 232.14;
	p.maxi[0] = 230.80;
	p.mini[1] = 232.14;
	p.maxi[1] = 231.28;
	p.mini[2] = 175.74;
	p.maxi[2] = 175.42;
	p.mini[3] = 175.74;
	p.maxi[3] = 175.26;
	p.mini[4] = 197.32;
	p.maxi[4] = 198.67;

	// point 3 my values

	p.mymini[0] = 0.1552;
	p.mymaxi[0] = 0.1547;
	p.mymini[1] = 0.1552;
	p.mymaxi[1] = 0.1540;
	p.mymini[2] = 0.1526;
	p.mymaxi[2] = 0.1520;
	p.mymini[3] = 0.1526;
	p.mymaxi[3] = 0.1506;
	p.mymini[4] = 0.1318;
	p.mymaxi[4] = 0.1313;

	// point 3 mz values

	p.mzmini[0] = 1.0781;
	p.mzmaxi[0] = 1.0715;
	p.mzmini[1] = 1.0781;
	p.mzmaxi[1] = 1.0742;
	p.mzmini[2] = 1.2583;
	p.mzmaxi[2] = 1.2530;
	p.mzmini[3] = 1.2583;
	p.mzmaxi[3] = 1.2570;
	p.mzmini[4] = 0.9163;
	p.mzmaxi[4] = 0.9229;

	pval[43]=p;

	// point 4 p values

	p.mini[0] = 232.14;
	p.maxi[0] = 231.12;
	p.mini[1] = 232.14;
	p.maxi[1] = 231.62;
	p.mini[2] = 175.74;
	p.maxi[2] = 175.50;
	p.mini[3] = 175.74;
	p.maxi[3] = 175.99;
	p.mini[4] = 197.32;
	p.maxi[4] = 198.35;

	// point 4 my values

	p.mymini[0] = 0.1552;
	p.mymaxi[0] = 0.1542;
	p.mymini[1] = 0.1552;
	p.mymaxi[1] = 0.1550;
	p.mymini[2] = 0.1526;
	p.mymaxi[2] = 0.1500;
	p.mymini[3] = 0.1526;
	p.mymaxi[3] = 0.1518;
	p.mymini[4] = 0.1318;
	p.mymaxi[4] = 0.1309;

	// point 4 mz values

	p.mzmini[0] = 1.0781;
	p.mzmaxi[0] = 1.0758;
	p.mzmini[1] = 1.0781;
	p.mzmaxi[1] = 1.0730;
	p.mzmini[2] = 1.2583;
	p.mzmaxi[2] = 1.2622;
	p.mzmini[3] = 1.2583;
	p.mzmaxi[3] = 1.2552;
	p.mzmini[4] = 0.9163;
	p.mzmaxi[4] = 0.9186;

	pval[36]=p;

	// point 5 p values

	p.mini[0] = 232.14;
	p.maxi[0] = 231.62;
	p.mini[1] = 232.14;
	p.maxi[1] = 231.12;
	p.mini[2] = 175.74;
	p.maxi[2] = 175.99;
	p.mini[3] = 175.74;
	p.maxi[3] = 175.50;
	p.mini[4] = 197.32;
	p.maxi[4] = 197.85;

	// point 5 my values

	p.mymini[0] = 0.1552;
	p.mymaxi[0] = 0.1550;
	p.mymini[1] = 0.1552;
	p.mymaxi[1] = 0.1542;
	p.mymini[2] = 0.1526;
	p.mymaxi[2] = 0.1519;
	p.mymini[3] = 0.1526;
	p.mymaxi[3] = 0.1499;
	p.mymini[4] = 0.1318;
	p.mymaxi[4] = 0.1317;

	// point 5 mz values

	p.mzmini[0] = 1.0781;
	p.mzmaxi[0] = 1.0730;
	p.mzmini[1] = 1.0781;
	p.mzmaxi[1] = 1.0758;
	p.mzmini[2] = 1.2583;
	p.mzmaxi[2] = 1.2552;
	p.mzmini[3] = 1.2583;
	p.mzmaxi[3] = 1.2621;
	p.mzmini[4] = 0.9163;
	p.mzmaxi[4] = 0.9213;

	pval[35]=p;

}

double interpolate(double x, double x1,double y1, double x2,double y2){
	double y;
	y = y1 + ((x-x1)*(y2-y1))/(x2-x1);
	return y;
}

bool calc(vector<double>v,double val){
	itno++;
	cout<<"Iteration No : "<<itno<<endl;
	vector<double>b,my,mz;
	b.resize(5);
	my.resize(5);
	mz.resize(5);
	int k,i;
	int rr,ss;

	for(k=0;k<5;k++){
		b[k]=0;
		my[k]=0;
		mz[k]=0;
		double x,xx,xxx;
		double yy=0,y=0;
		for(i=0;i<v.size();i++){
			x = interpolate(v[i],0,pval[nodalpt[i]].mini[k],1,pval[nodalpt[i]].maxi[k]);
			xx = interpolate(v[i],0,pval[nodalpt[i]].mymini[k],1,pval[nodalpt[i]].mymaxi[k]);
			xxx = interpolate(v[i],0,pval[nodalpt[i]].mzmini[k],1,pval[nodalpt[i]].mzmaxi[k]);

			b[k]+=(v[i]*x);
			my[k]+=(v[i]*xx);
			mz[k]+=(v[i]*xxx);
			y+=v[i];
		}


		rr = int(floor(y));
		ss = int(ceil(y));

		if(rr!=ss){
			yy = interpolate(y,floor(y),irange[rr],ceil(y),irange[ss]);
			b[k]/=yy;

			yy = interpolate(y,floor(y),myrange[rr],ceil(y),myrange[ss]);
			my[k]/=yy;

			yy = interpolate(y,floor(y),mzrange[rr],ceil(y),mzrange[ss]);
			mz[k]/=yy;
		}
		else{
			yy=y;
			b[k]/=yy;
			my[k]/=yy;
			mz[k]/=yy;
		}
	}


	int flag = 0;
	//cout<<val<<endl;

	for(k=0;k<5;k++){
		beams[beamno[k]].n = b[k]/beams[beamno[k]].pd;
		beams[beamno[k]].k = 1 + 0.8*beams[beamno[k]].n;
		beams[beamno[k]].ratio = beams[beamno[k]].n + ((0.54 * beams[beamno[k]].k * my[k])/(beams[beamno[k]].md)) + ((0.9 * beams[beamno[k]].k * mz[k])/(beams[beamno[k]].md));
		//cout<<beamno[k]<<" "<<b[k]<<" "<<my[k]<<" "<<mz[k]<<" "<<beams[beamno[k]].ratio;
		if(beams[beamno[k]].ratio >= val){
			flag=1;
			break;
		}

		/*if(flag==0){
			cout<<" Pass \n";
		}
		else{
			cout<<" Fail \n";
		}*/
	}

	if(flag==0){
		return true;
	}
	else{
		return false;
	}

}

void combinationUtil(int arr[], int n, int r, int index, vector<int>&data, int i){
    if (index == r){
    	comb.push_back(data);
        return;
    }

    if (i >= n)
        return;
 
    data[index] = arr[i];
    combinationUtil(arr, n, r, index+1, data, i+1);
    combinationUtil(arr, n, r, index, data, i+1);
}

void findCombination(int arr[], int n, int r){
    vector<int>data;
    data.resize(r);
    combinationUtil(arr, n, r, 0, data, 0);
}

bool check(vector<int>&t,int val){
	int i;
	for(i=0;i<t.size();i++){
		if(t[i]==val){
			return true;
		}
	}
	return false;
}

void recurse(vector<double>&t,vector<int>&tt,int i,int n){
	if(i==n){
		lst.insert(t);
		/*for(int k=0;k<n;k++){
			cout<<t[k]<<" ";
		}
		cout<<endl;*/
		return;
	}
	else{
		double force;
		for(force=0.2;force<=1;force+=0.13){
			if(check(tt,i)){
				t.push_back(force);
			}
			else{
				t.push_back(0);
			}
			recurse(t,tt,i+1,n);
			t.pop_back();
		}
	}
}

void findresult(int n,int r,double val){
	int arr[]={0,1,2,3,4,5};
	findCombination(arr,n,r);

	int i,j,k;
	vector<double>ans;
	//cout<<comb.size()<<endl;
	for(i=0;i<comb.size();i++){
		vector<double>temp;

		/*for(j=0;j<comb[i].size();j++){
			cout<<comb[i][j]<<" ";
		}
		cout<<endl;*/

		for(j=0;j<comb[i].size();j++){
			lst.clear();
			recurse(temp,comb[i],0,n);
			for(it=lst.begin();it!=lst.end();it++){
				if(calc(*it,val)){
					ans = *it;
					break;
				}
			}
		}
	}

	next:
	cout<<"Result :\n";
	for(i=0;i<ans.size();i++){
		cout<<nodalpt[i]<<" "<<ans[i]<<endl;
	}

}

int main(){
	init();
	findresult(6,3,0.9999);
}