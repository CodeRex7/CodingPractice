 
    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int n;
    	scanf("%d",&n);
    	assert(n>0 and n<=1e6);
    	long long int sum[n];
    	for(int i=0;i<n;i++){
    		sum[i]=0;
    	}
    	for(int i=0;i<3;i++){
    		for(int j=0;j<n;j++){
    			long long int x;
    			scanf("%lld",&x);
    			assert(x>0 and x<=1e9);
    			sum[j]-=x;
    		}
    	}
    	priority_queue < long long int > queue;
    	for(int i=0;i<n;i++){
    		queue.push(sum[i]);
    	}
    	int q;
    	scanf("%d",&q);
    	assert(q>0 and q<=1e4);
    	while(q--){
    		int k;
    		scanf("%d",&k);
    		assert(k>0 and k<=1e3);
    		if(k>queue.size()){
    			printf("-1\n");
    		}
    		else{
    			long long int temp[k-1];
    			for(int i=0;i<k-1;i++){
    				temp[i]=queue.top();
    				queue.pop();
    			}
    			printf("%lld\n",-queue.top());
    			queue.pop();
    			for(int i=k-2;i>=0;i--){
    				queue.push(temp[i]);
    			}
    		}
    	}
    	return 0;
    }
 