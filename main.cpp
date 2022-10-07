//
// Created by Mehmet Uzgoren on 7/30/22.
//
#include "Project8Class.h"

#import <unordered_map>
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i,j = 0;
        vector <int> ans;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                i++;
            }



        }
        return ans;
    }
};

int main(void) {
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    Solution s;
    vector<int> nums3 = s.intersect(nums1, nums2);
    for(int i=0; i<nums3.size(); i++){
        cout<<nums3[i]<<endl;
    }
}
//    cout<<"TestCase 1"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("test1.blip");
//    run();
//    //test1();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
//
//    cout<<"TestCase 2"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("test2.blip");
//    run();
//    //test2();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
//
//    cout<<"TestCase 3"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("test3.blip");
//    run();
//    //test3();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
//
//    cout<<"TestCase 4"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("test4.blip");
//    run();
//    //test4();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
//
//    cout<<"Extra TestCase 0"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("extra_test0.blip");
//    run();
//    //test4();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
//
//    cout<<"Extra TestCase 1"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("extra_test1.blip");
//    run();
//    //test4();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
//
//    cout<<"Extra TestCase 2"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("extra_test2.blip");
//    run();
//    //test4();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
//
//    cout<<"Extra TestCase 3"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("extra_test3.blip");
//    run();
//    //test4();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
//
//    cout<<"Extra TestCase 4"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("extra_test4.blip");
//    run();
//    //test4();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
//
//    cout<<"Extra TestCase 5"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("extra_test5.blip");
//    run();
//    //test4();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
//
//    cout<<"Extra TestCase 6"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("extra_test6.blip");
//    run();
//    //test4();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
//
//    cout<<"Extra TestCase 7"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("extra_test7.blip");
//    run();
//    //test4();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
//
//    cout<<"Extra TestCase 8"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("extra_test8.blip");
//    run();
//    //test4();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
//
//    cout<<"Extra TestCase 9"<< endl;
//    cout<<"---------------------"<<endl;
//    set_input("extra_test9.blip");
//    run();
//    //test4();
//    cout<<"---------------------"<<endl;
//    cout<<endl;
