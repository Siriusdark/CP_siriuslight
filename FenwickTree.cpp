template <class Type>
class FenwickTree{
	Type T[N];
	FenwickTree(){
		fill(T, T + N, 0);
	}
	
	void update(int index, int value){
		while(id <= n){
			T[id] += value;
			id += (id & -id);
		}
	}

	Type query(int id){
		int res = 0;
		while(id >= 1){
			res += T[id];
			id -= (id & -id);
		}
		return res; 
	}
};

FenwickTree FT;
