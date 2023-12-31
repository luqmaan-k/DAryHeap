
            }
            cout<<endl;
            break;
         }
         case 2:
         {
            int key;
            cout<<"Enter the value to be inserted: ";
            cin>>key;
            insert(arr,d,key);
            cout<<"Insertion - successful"<<endl;
            break;
         }
         case 3:
         {
            for(int i = (arr.size()-1)/(d+1); i >= 0; i--)
            {
               heapify(arr,d,i);
            }
            cout<<"Heapify - successful"<<endl;
            break;
         }
         case 4:
         {
            V sorted = heapsort(arr,d);
            cout<<"Sorted List"<<endl;
            for(int i : sorted)
            {
               cout<<i<<" ";
            }
            cout<<endl;
            break;
         }
         case 5:
         {
            if(arr.empty())
               cout<<"Heap is empty"<<endl;
            else
               cout<<"Deleting maximum element: "<<deleteMax(arr,d)<<endl;
            break;
         }
         case 6:
         {
            if(arr.empty())
               cout<<"Heap is empty"<<endl;
            else
               cout<<"Extracting minimum element: "<<extractMin(arr,d)<<endl;
            break;
         }
         case 0:
         {
            break;
         }
         default:
         {
            cout<<"Invalid choice"<<endl;
         }
      }
   }
   while(choice != 0);

   return 0;
}

void heapify(V& hT,int d,int i)
{
   if(d*i+1 >= hT.size())
      return;

   int max=i;
   auto m = max_element(hT.begin() + d*i+1 , min(hT.begin() + d*(i+1)+1 , hT.end                                                                                                                     ())); //Max of children of i-th node

//   cout<<"hT[max]: "<<hT[max]<<endl;
//   cout<<"*m: "<< *m <<endl;
//   cout<< *(hT.begin() + d*(i+1)) <<endl;

   if(hT[max] < *m)
   {
      swap(*m,hT[max]);
      heapify(hT,d,m - hT.begin());
   }
}

void insert(V& hT,int d,int key)
{
   hT.push_back(key);
   for(int i = (hT.size()-1)/(d+1); i >= 0; i--)
   {
      heapify(hT,d,i);
   }
}

int deleteMax(V& hT,int d)
{
   for(int i = (hT.size()-1)/(d+1); i >= 0; i--)
   {
      heapify(hT,d,i);
   }

   int max = hT[0];
   swap(hT[0],hT[hT.size()-1]);
   hT.pop_back();
   heapify(hT,d,0);
   return max;
}

V heapsort(V hT,int d)
{
   V sorted;
   for(int i = (hT.size()-1)/(d+1); i >= 0; i--)
   {
      heapify(hT,d,i);
   }

   for(int i = hT.size() - 1; i >= 0; i--)
   {
      sorted.insert(sorted.begin(),hT[0]);
      swap(hT[0],hT[i]);
      hT.pop_back();
      heapify(hT,d,0);
   }
   return sorted;
}

int extractMin(V& hT,int d)
{
   hT = heapsort(hT,d);
   int min=hT[0];
   hT.erase(hT.begin());

   for(int i = (hT.size()-1)/(d+1); i >= 0; i--)
   {
      heapify(hT,d,i);
   }
   return min;
}
