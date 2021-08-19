#ifndef RLE             //File stuff
#define RLE             //File stuff

#include <vector>       //Data type we are dealing with is vectors

//Implements the run-length algorithm for data compression
//https://en.wikipedia.org/wiki/Run-length_encoding
class run_length {
    public:
        std::vector<int> compress(std::vector<int> input) {
            
            //We know there is ar least one instance of the first element in the input
            std::vector<int> compressed = {1, input[0]};
            int count = 1;

            //Loop through every element in vector
            for(int i = 1; i < input.size(); i++) {
                
                //If there is a repeat character
                if(input[i] == input[i-1]) {
                    //Increment the second to last element
                    compressed[compressed.size()-2]++;
                
                //If the character is unique
                } else {
                    //Indicate that there is one 
                    //instance of this character and 
                    //then indicate that character after it
                    compressed.push_back(1);
                    compressed.push_back(input[i]);
                }

            }

            return compressed;
        }

        std::vector<int> decompress(std::vector<int>& nums) {
        
            std::vector<int> decompressed;
            
            //Loop through every other element in the list
            //(every pair)
            for(int i = 0; i < nums.size(); i+=2) {
                
                //Grab our values
                int freq = nums[i];
                int val = nums[i+1];
                
                //Unzip
                for(int j = 0; j < freq; j++) {
                    decompressed.push_back(val);
                }
            }
            
            return decompressed;
        
    }
};

#endif