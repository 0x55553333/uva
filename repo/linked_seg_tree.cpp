class Node{
public:
	Node *l, *r;
	int s, e;
	ll sum, maxi;
	Node(int a, int b){
		s = a;
		e = b;
		maxi = 0LL;
		sum = 0LL;
		if(s!=e){
			l = new Node(s,(s+e)/2);
			r = new Node((s+e)/2+1,e);
		}
	}
	void pull(){
		if(s==e){
			return;
		}
		sum = l->sum + r->sum;
		sum = min(sum,inf);
		maxi = max(l->maxi,r->maxi);
	}
	void add(int ind, ll val){
		if(s==ind && e==ind){
			sum += val;
			sum = min(sum,inf);
			maxi = sum;
			return;
		}
		if(ind<=(s+e)/2){
			l->add(ind,val);
		}
		else{
			r->add(ind,val);
		}
		pull();
	}
	ll gsum(int st, int en){
		if(st<=s && e<=en){
			return sum;
		}
		ll ret = 0LL;
		if(st<=(s+e)/2){
			ret += l->gsum(st,en);
		}
		if(en>(s+e)/2){
			ret += r->gsum(st,en);
		}
		ret = min(ret,inf);
		return ret;
	}
	ll getmax(int st, int en){
		if(st<=s && e<=en){
			return maxi;
		}
		ll ret = 0;
		if(st<=(s+e)/2){
			ret = max(ret,l->getmax(st,en));
		}
		if(en>(s+e)/2){
			ret = max(ret,r->getmax(st,en));
		}
		return ret;
	}
};

