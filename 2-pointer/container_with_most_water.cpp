
//The logic used in the maxArea function is based on the two-pointer approach. This approach aims to maximize the area between two lines in the vector by strategically moving two pointers towards each other. Initially, the pointers left and right are positioned at the two ends of the height vector. In each iteration of the loop, the function calculates the area formed by the two lines determined by the current positions of the pointers. It updates the max_area variable with the maximum of the current area and the previously calculated maximum area. Then, it compares the heights of the lines pointed to by the left and right pointers. If the height of the line pointed to by the right pointer is smaller than the height of the line pointed to by the left pointer, it decrements the right pointer, effectively moving towards the center of the vector. Conversely, if the height of the line pointed to by the left pointer is smaller than or equal to the height of the line pointed to by the right pointer, it increments the left pointer, moving it towards the center. This process continues until the left and right pointers meet, ensuring all possible areas are considered. Finally, the function returns the maximum area found.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max_area=0;

        while(right>left)
        {         

            int area = (right - left) * min(height[left], height[right]);
            max_area = max(max_area, area);
            if(height[right]<height[left])
            {
                right--;
            }
            else
            {
                left++;
            }

        }
        return max_area;
        
    }
};