// 큐 테스트 출력
    queue<int> test = que;
    while(!test.empty()){
        cout << test.front() << " ";
        test.pop();  
    }        
    cout << endl;