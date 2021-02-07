一、分治、回溯的实现和特性
    分治的代码模板
    int divide_conquer(Problem *problem, int params)
    {  // recursion terminator  
      if (problem == nullptr)  {    
           process_result   
           return return_result;  
       }  
       // process current problem  
       subproblems = split_problem(problem, data)  
       subresult1 = divide_conquer(subproblem[0], p1)  
       subresult2 = divide_conquer(subproblem[1], p1)  
       subresult3 = divide_conquer(subproblem[2], p1)  
       ...  
       // merge  
       result = process_result(subresult1, subresult2, subresult3)  
       // revert the current level status   
       return 0;}
二、深度优先搜索和广度优先搜索
     DFS代码模板：
     //C/C++//递归写法：
     map<int, int> visited;
     void dfs(Node* root) {  
     // terminator  
     if (!root) return ;  
     if (visited.count(root->val)) {    
     // already visited    
         return ;  
      }  
      visited[root->val] = 1;  
      // process current node here.   
      // ...  
      for (int i = 0; i < root->children.size(); ++i) {    
      dfs(root->children[i]);  
      }  
      return ;
      }
      //C/C++//非递归写法：
      void dfs(Node* root) { 
        map<int, int> visited;  
        if(!root) return ;  
        stack<Node*> stackNode;  
        stackNode.push(root);  
        while (!stackNode.empty()) { 
           Node* node = stackNode.top();    
           stackNode.pop();   
           if (visited.count(node->val)) continue;    
           visited[node->val] = 1;    
           for (int i = node->children.size() - 1; i >= 0; --i) {        
               stackNode.push(node->children[i]);   
            }  
          }  
          return ;
          }
          BFS代码模板：
          // C/C++
          void bfs(Node* root) {  
             map<int, int> visited;  
             if(!root) return ;  
             queue<Node*> queueNode;  
             queueNode.push(root);  
             while (!queueNode.empty()) {    
                  Node* node = queueNode.top();    
                  queueNode.pop();    
                  if (visited.count(node->val)) continue;   
                  visited[node->val] = 1;    
                  for (int i = 0; i < node->children.size(); ++i) {    
                  queueNode.push(node->children[i]);    
                  }  
               } 
               return ;
           }
 三、贪心算法
     局部最优不应定全局最优，贪心法的使用需要满足一些特殊情况，关键在于证明局部最优会得到全局最优。
 四、二分查找
     二分查找的前提：
     1.目标函数单调性
     2.存在上下界
     3.能够通过索引访问
     二分查找的模板：
     int binarySearch(const vector<int>& nums, int target) {	
         int left = 0, right = (int)nums.size()-1;		
         while (left <= right) {		
            int mid = left + (right - left)/ 2;		
            if (nums[mid] == target) 
                 return mid;		
             else if (nums[mid] < target) 
                 left = mid + 1;	
            else 
                 right = mid - 1;	
          }		
          return -1;
       }
       寻找一个半有序数组[4,5,6,7,0,1,2]中间无序的地方：
       思考:
            这道题其实和寻找寻找旋转排序数组中的最小值类似。无序的地方就是最大值和最小值交接的地方。因此寻找最小值或者最大值即可。
            这里以寻找最小值为例：
            使用二分查找的方法，head =0,tail =n-1,n是数组的数值数量。
            二分之后一定mid值一侧有序，另一侧无序。
                最好的情况：第一次二分的时候，最大个最小交接的地方在中间，通过比较num[mid]和num[mid-1]和num[mid+1],即可知道无序产生的地方。
                如果第一次没找到无序地方，就切换到无序的一侧，按照上述二分的方法继续进行查找。
                如此一直找下去，直到找到为止。
            代码：int findMin(int* nums, int numsSize){
                      int left=0,right=numsSize-1,mid;
                      if(numsSize==1){
                          return nums[0];
                      }
                      if(nums[0]<nums[right]){
                          return nums[0];
                      }
                      while(left<=right){
                          mid =(left+right)/2;
                          if(nums[mid]>nums[mid+1]){
                              return nums[mid+1];
                          }
                          if(nums[mid]<nums[mid-1]){
                              return nums[mid];
                          }
                          if(nums[0]<nums[mid]){
                              left =mid + 1;
                          }
                          else{
                              right =mid -1;
                          }
                      }
                      return -1;
                  }
  
       
 
 
 
          
 
