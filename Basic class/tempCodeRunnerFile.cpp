while(1){
        if(prime(n)){
            cout << "prime check" << endl;
            s = to_string(n);
            cout << "string check start" << endl;
            cout << s << endl;
            cout << "string check end" << endl;
            cout << "pen check start" << endl;
            cout << pen(s) << endl;
            cout << "pen check end" << endl;
            if(pen(s)){
                cout << s;
                return 0;
            }
            n++;
        }
        else{
            n++;
        }
    }