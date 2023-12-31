#include <bits/stdc++.h>
using namespace std;
int main()	{

	// a pattern
	// for(int i=1; i<5; i++)	{
	// 	for(int j=1; j<=i; j++)
	// 		cout<<j;
		
	// 	for(int j=1; j<2*(5-i)-1;j++)
	// 		cout<<" ";

	// 	for(int j=i; j>=1; j--)
	// 		cout<<j;

	// 	cout<<endl;
	// }

	//another pattern
	// for(int i=0; i<2*4-1;i++)	{
	// 	for(int j=0;j<2*4-1;j++)	{
	// 		int top = i;
	// 		int left = j;
	// 		int right = 2*4 - 2 -j;
	// 		int bottom = 2*4 - 2 -i;

	// 		cout<<(4 - min(min(top,bottom), min(left,right)));
	// 	}

	// 	cout<<endl;
	// }


	//STL library data structures and containers

	//all below functions used with containers have t(n) = O(1) except specifically mentioned ones

	//pairs in containers
	// pair<int, int> p1 = {1, 3};
	// cout<<p1.first<<" "<<p1.second;

	// //nested pairing
	// pair<int, pair<int, int>> p = {1, {2, 3}};
	// cout<<"\n"<<p.first<<" "<<p.second.first<<" "<<p.second.second;

	// //array pairs
	// pair<int, int> arr[] = { {1, 2},{1, 3},{1, 4},{1, 5}};
	// cout<<"\n"<<arr[1].second;

	//about vectors
	vector<int> v;
	v.push_back(1);
	v.emplace_back(2);//faster than push back

	vector<int, int> v1;
	v1.push_back({1, 2});
	v1.emplace_back(1,2);//auto assumes args as pairs and inserts

	vector<int> v2(5, 100); //a vector with size = 5 and all values = 100
	// vector<int> v2(5);//same as above but only size

	vector<int> v3(5,20);
	vector<int> v2(v3); //v2 is copy of v3

	//accessing vector elements
	vector<int>::iterator it = v.begin();//'it' points to memory location where first value of vector is stored
	it++; //increment can be by +1 or by +2 or by -1 or by -2 i.e. +x or -x
	cout<<*(it)<<" ";//'it' points to memeory address => it is an address => '*' is used to access data at that memeory location

	vector<int>::iterator i = v.end(); //points to the location just ahead of the memeory location of last value in the vector i.e. i-- will actually point to the memory location of last value

	cout<<v[0]<<" ";//accessing specific values

	cout<<v.back()<<" ";//last value of the vector

	//printing vector

	//declaring iterator
	for(vector<int>::iterator it = v.begin(); it!=v.end(); it++)	{
		cout<<*(it)<<" ";
	}

	//declaring iterator using 'auto' that literally does what it does
	for(auto it = v.begin(); it!=v.end(); it++)	{
		cout<<*it<<" ";
	}

	//using for-each loop
	for(auto it: v)	{
		cout<<it<<" ";
	}

	//operations in vector
	v.erase(v.begin() + 1); //erase second value
	v.erase(v.begin() + 2, v.begin() + 4);//erase values that lie between [2, 4) i.e. in general [start, end)

	v.insert(v.begin(), 300);//inserts 300 as the first value of vector pushing others back i.e. size also increases i.e. it does not replace the first value but gets added before the initial first value
	v.insert(v.begin() + 1, 2, 10);//inserts values after adding 1 to v.begin() i.e. right after the first value and hence, adds value '10' 2 times 

	vector<int> copy(2, 50);
	v.insert(v.begin(), copy.begin(), copy.end());//copies a portion of vector 'copy'[in this case the whole vector], and inserts it right after the first value in vector 'v'

	cout<<v.size();//outputs the size of vector

	v.pop_back();//deletes last element

	v1.swap(v2);//swaps values in v1 and v2

	v.clear();//removes an entire vector

	cout<<v.empty();//retrun true of vector is empty else false


	//lists in stl

	list<int> ls;

	ls.push_back(1);
	ls.emplace_back(3);
	//inserting at front of list
	ls.push_front(4);
	ls.emplace_front(3);


	//D-queue

	deque<int> dq;
	dq.push_back(1);
	dq.emplace_back(2);
	dq.push_front(7);
	dq.emplace_front(8);
	dq.pop_back();
	dq.pop_front();


	dq.back();
	dq.front();


	//stack in stl

	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.emplace(5);

	cout<<s.top();

	s.pop();

	cout<<s.size();

	cout<<s.empty();

	stack<int>s1, s2;
	s1.swap(s2);

	//queue in stl

	queue<int> q;
	q.push(1);
	q.push(3);
	q.emplace(2);
	q.back() += 9;
	cout<<q.back();

	cout<<q.front();

	q.pop();

	cout<<q.front();

	//priority queue in stl :  data not stored linearly but in form of trees so that top() always give highest value if type is int and largest string lexicographically if type is str

	priority_queue<int> pq;
	pq.push(1);
	pq.push(2);// t(n) = log(n)
	pq.emplace(3);

	cout<<pq.top();

	pq.pop();// t(n) = log(n) rest all have time compexity = O(1)

	cout<<pq.top();

	//above is max heap and below is min heap

	//minimum heap i.e. gettig min value not the largest value as in normal pq
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(5);
	pq.push(2);
	pq.push(8);
	pq.emplace(10);
	cout<<pq.top(); //prints 2


	//set in stl
	// set = sorted + unique => hence not linear container but tree is maintained
	//all operations take log(n) time
	set<int> st;
	st.insert(1);
	st.insert(2);
	st.insert(2); //wont store
	st.insert(4);
	st.insert(3); //will store between 2 and 4 i.e. sorted
	
	auto it = st.find(3);//will return it = address that points at memory location of value = 3

	auto it = st.find(5); //will return it = st.end() i.e. address just after the last element

	st.erase(5);//t(n) = log(n)

	int cnt = st.count(1);//will return 1 if it exists(only 1 occurence) else 0

	auto it = st.find(3);
	st.erase(*it); //giving pointer to iterator to erase a element it takes contant time

	auto it1 = st.find(2);
	auto it2 = st.find(4);
	st.erase(it1, it2);//same as [start, end)

	auto it = st.lower_bound(2);
	auto it = st.upper_bound(3);


	//multiset in stl
	//multiset = sorted not unique

	multiset<int> ms;
	ms.insert(6);
	ms.insert(6);
	ms.insert(6);
	ms.insert(6);// stores all occurences of 6 i.e. ms = {6, 6, 6, 6}

	ms.erase(6); //will erase all 6 and ms will be empty

	int cnt = ms.count(6);//will give total occurences i.e. 4

	ms.erase(ms.find(6));//find() will return first occurence of 6 and erase() will remove the address/portion not the element, like it will remov the link -> as in linklist we break links

	ms.erase(ms.find(6), ms.find(6) + 2);// will remove first 2 occurences of 6

	//unordered set in stl
	//unordered = unsorted + non-unique
	//stores in randomized order
	//has better t(n) than set in most cases except when collision happens
	//all operations are same with t(n) = O(1); except lower and upper bounds don't work
	unordered_set<int> us;
	us.insert(1);
	us.insert(1);
	us.insert(2);
	us.insert(5);
	us.insert(3);


	//maps in stl
	//map stores unique keys in sorted order; kind of similar to set
	//have t(n) = log(n)
	map<int, int> m; // key: value
	map<int, pair<int, int>> mp; // key: {value, value}
	map< pair<int, int>, int> mpp; // {key, key}: value

	m[1] = 2;
	m.emplace({3, 1});
	m.insert({2, 4});
	mpp[{2, 3}] = 10;

	for(auto it: m)	{
		cout<<it.first<<" "<<it.second<<endl;
	}

	cout<<m[1];
	cout<<m[5]; //prints 0 or null as 5 doesn't exist

	auto it = m.find(3);
	cout<<*(it).second;

	auto it = m.find(5); // points to end() i.e. after the map's last element

	auto it = m.lower_bound(2);
	auto it = m.upper_bound(3);

	//multimap => same as map except it allows duplicate keys
	//unorderd map => allows unique keys but unsorted, like unordered set and has t(n) = O(1)

	//sorting
	int a[n];
	sort(a, a+n); //sorts an array of size n with first element pointing to 'a'
	sort(v.begin(), v.end()); //sorts a vector of size v.begin() -> v.end()

	sort(a + 2, a + 4);//sorts only between [(a+2), (a+4)] i.e. size of two elements starting from the 3rd element of the array
	sort(a, a+n, greater<int>); //sorts in DESC order

	pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
	//sorting above array in custom way i.e. neither ASC nor DESC
	//sorting condition: sort according to second element(will be assumed as ASC by default), but if second element is same then sort according to first element but in DESC

	sort(a, a + n, comp);//comp is a self written comparator which is a boolean function

	bool comp(pair<int, int> p1, pair<int, int> p2)	{ //just pick up two example pairs to write function for comparator, don't think in terms of whole arrays
		//second elements are unequal
		if(p1.second < p2.second) return true;
		if(p1.second > p2.second) return false; //comp will swap them internally so that they are in correct order

		//when they are equal
		if(p1.first < p2.first) return true;
		return false;
	}

	//important builtin function

	int num = 7;
	int cnt = __builtin_popcount(); //returns number of set bits or bits = number of 1s in binary

	long long num = 3254353335435;
	int cnt = __builtin_popcountll();//works same way

	//all permutations
	string s = "123";//string must be sorted if s = 231 it will result in 231, 312, 321 and then no permutation => false -> exit the loop hence string must be sorted
	sort(s.begin(), s.end());
	do	{
		cout<<s<<endl;
	}while(next_permutation(s.begin(), s.end()));

	int max = *max_element(a, a+n);//returns max element of the array
	int min = *min_element(a, a+n);

	//extraction of digits ( t(n) = log(n) base 10 becoz we are doing n=n/10 )
	//1. take (%) of 10 with the number
	//2. divide by ten 
	//3. repeat until you get zero
	//if you notice number of digits = quotient i.e. how many times we divide the number by 10
	//so logarithmic approach can also be used i.e. digits = log(n) + 1; log with base 10 and auto type-cast it to 'int' to get only integer part
	

	//printing divisors ( t(n) = O(sqrt(n)) )
	//1. one way is to use n%i==0 condition
	//2. second way is : 
		//there is a pattern in divisors : 1x36, 2x18, 3x12, 4x9, 6x6 after this same numbers keep repeating unitl 36x1 except their positions are interchanged and also note that there is apttern of i x (n/i) for every term i.e. 1x(36/1), 2x(36/2=18),...and so on
		//so we need to only loop till sqrt(n) becoz after that the same number will be repeated hence we need to stop when same divisors are encountered
		//thus condition becomes :
			for(int i=0; i<sqrt(n);i++)	{ //or i*i <= n as sqrt will take some time
				if(n%i==0)
				cout << (i);
				if(n/i != i)
					cout << (n/i);
			}
		//using above method gives unsorted factors to achive sorted order sue list/vector etc..
	

	//prime number : number that has only 2 factors i.e. 1 and itself
	//using same above method to determine whether a number is a prime or not
	for(int i=0; i*i<=n;i++)	{
		if(n%i==0)
			count++;
			if((n/i) != i)
				count++;

	}
	if(count ==2); //it is prime else not;


	//gcd or hcf
	//1.brute force method
	int hcf = 1;
	for(int i=0;i<min(n1,n2);i++){
		if(n1%i==0 && n2%i==0)
			hcf = i;
	}
	cout<<hcf;
	//2. euclidean algo ( t(n) = O(log(min(a, b)) with base c(will fluctuate but no need for it) ) : gcd(a,b) = gcd(a-b, b) but this will become much larger numbers have too much of a difference 
	//e.g. gcd(52,10) = gcd(52-10,10) = gcd(42,10) = gcd(42-10,10) = gcd(32,10) = gcd(32-10,10) = gcd(22,10) = gcd(22-10,10) = gcd(12,10) = gcd(12-10,10) = gcd(2,10)
	//now we will have to swap again i.e. gcd(10,2) and continue the process and result would be 2....but if you note we obtained gcd(2,10) at exactly 5 steps i.e. 52%10 = 5 so instead of '-' we can do '%' and swap numbers if left one becomes smaller
	//thus following logic is formed :
	while(n1>0 && n2>0)	{ //we will have to decrease the numbers too, until one of them becomes 0 then the other one will be the gcd of the two given numbers
	if(n1>=n2)
		n1=n1%n2;
	else
		n2=n2%n1;
	}

	if(n1==0) cout<<n2;
	else cout<<n1;























	return 0;

}