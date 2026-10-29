#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip> 
#include <algorithm>

//headers
#include "BST.h"
#include "AVL.h"
#include "LinkedList.h"

//Made a template to easily use the different classes
template <typename StructureType> 
double benchmarkInsertion (StructureType& ds, const std::vector<int>& data)
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now(); //start clock

    for (int val: data)
    {
        ds.insert(val);
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now(); //end clock

    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);//calculate duration in nanoseconds
    return duration_ns.count();
}
double benchmarkInsertion (LinkedList& ds, const std::vector<int>& data) 

{
      std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now(); //start clock

    for (int val: data)
    {
        ds.append(val);
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now(); //end clock

    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);//calculate duration in nanoseconds
    return duration_ns.count();
}

template<typename StructureType>
double benchmarkSearch(StructureType& ds, int target, int &isfound)
{
    //start clock
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now(); 

    bool found = ds.search(target);
   
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now(); //end clock

    auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);//calculate duration in nanoseconds
    
    isfound = found;
    return duration_ns.count();
}

std::vector<int> GenerateRand(size_t size);
std::vector<int> GenerateASC(size_t size);
std::vector<int> GenerateDESC(size_t size);
int RNG();

int main()
{
    std::cout << "====== BENCHMARK: 500,000 ======" << std::endl;

        std::vector<int> rand500k = GenerateRand(500000); //generate numbers

        //INSERTIONS

        //BST
        BST bst500k; //create an instance of BST
        double bst500k_insert = benchmarkInsertion(bst500k, rand500k);
        //AVL
        AVL avl500k;
        double avl500k_insert = benchmarkInsertion(avl500k, rand500k);
        //LL
        LinkedList LL500k;
        double LL500k_insert  = benchmarkInsertion(LL500k, rand500k);

        //SEARCH

        int target500k = RNG();
        int bstfound;
        int avlfound; 
        int LLfound;

        //BST
        double bst500k_search = benchmarkSearch(bst500k, target500k, bstfound);

        //AVL 
        double avl500k_search = benchmarkSearch(avl500k, target500k, avlfound);

        //LL
        double LL500k_search = benchmarkSearch(LL500k, target500k, LLfound);

      
        //INSERTION OUTPUT
        std::cout << std::endl;
        std::cout << "BST Insert Time (500 thousand): " << bst500k_insert << " nanoseconds" << std::endl;
        std::cout << "AVL Insert Time (500 thousand): " << avl500k_insert << " nanoseconds" << std::endl;
        std::cout << "LL Append Time (500 thousand): " << LL500k_insert << " nanoseconds" << std::endl;
        std::cout << std::endl;
        
        //SEARCH OUTPUT
        std::cout << std::endl;
        std::cout << "BST Search Time (500 thousand): " << "Number: " << target500k << " Found: " << bstfound << " Time: " << bst500k_search << " nanoseconds" << std::endl;
        std::cout << "AVL Search Time (500 thousand): " << "Number: " << target500k << " Found: " << avlfound << " Time: " << avl500k_search << " nanoseconds" << std::endl;
        std::cout << "LL Search Time (500 thousand): " << "Number: " << target500k << " Found: " << LLfound << " Time: " << LL500k_search << " nanoseconds" << std::endl;
        std::cout << std::endl;

        std::cout << "====== BENCHMARK: 1,000,000 ======" << std::endl;

        std::vector<int> rand1Mil = GenerateRand(1000000); //generate numbers

        //INSERTIONS
        //BST
        BST bst1Mil; //create an instance of BST
        double bst1Mil_insert = benchmarkInsertion(bst1Mil, rand1Mil);
        //AVL
        AVL avl1Mil;
        double avl1Mil_insert = benchmarkInsertion(avl1Mil, rand1Mil);
        //LL
        LinkedList LL1Mil;
        double LL1Mil_insert  = benchmarkInsertion(LL1Mil, rand1Mil);

        //TODO: SEARCH
        int target1M = RNG();

        //BST
        double bst1M_search = benchmarkSearch(bst1Mil, target1M, bstfound);

        //AVL 
        double avl1M_search = benchmarkSearch(avl1Mil, target1M, avlfound);

        //LL
        double LL1M_search = benchmarkSearch(LL1Mil, target1M, LLfound);


        //INSERTION OUTPUT
        std::cout << std::endl;
        std::cout << "BST Insert Time (1 million): " << bst1Mil_insert << " nanoseconds" << std::endl;
        std::cout << "AVL Insert Time (1 million): " << avl1Mil_insert << " nanoseconds" << std::endl;
        std::cout << "LL Append Time (1 million): " << LL1Mil_insert << " nanoseconds" << std::endl;
        std::cout << std::endl;
        
        // SEARCH OUTPUT

        std::cout << std::endl;
        std::cout << "BST Search Time (1 million): " << "Number: " << target1M << " Found: " << bstfound << " Time: " << bst1M_search << " nanoseconds" << std::endl;
        std::cout << "AVL Search Time (1 million): " << "Number: " << target1M << " Found: " << avlfound << " Time: " << avl1M_search << " nanoseconds" << std::endl;
        std::cout << "LL Search Time (1 million): " << "Number: " << target1M << " Found: " << LLfound << " Time: " << LL1M_search << " nanoseconds" << std::endl;
        std::cout << std::endl;

    std::cout << "====== BENCHMARK: 2,000,000  ======" << std::endl;

        std::vector<int> rand2Mil = GenerateRand(2000000); //generate numbers

        //INSERTIONS
        //BST
        BST bst2Mil; //create an instance of BST
        double bst2Mil_insert = benchmarkInsertion(bst2Mil, rand2Mil);
        //AVL
        AVL avl2Mil;
        double avl2Mil_insert = benchmarkInsertion(avl2Mil, rand2Mil);
        //LL
        LinkedList LL2Mil;
        double LL2Mil_insert  = benchmarkInsertion(LL2Mil, rand2Mil);

        //SEARCH
        int target2M = RNG();

        //BST
        double bst2M_search = benchmarkSearch(bst2Mil, target2M, bstfound);

        //AVL 
        double avl2M_search = benchmarkSearch(avl2Mil, target2M, avlfound);

        //LL
        double LL2M_search = benchmarkSearch(LL2Mil, target2M, LLfound);


        //INSERTION OUTPUT
        std::cout << std::endl;
        std::cout << "BST Insert Time (2 million): " << bst2Mil_insert << " nanoseconds" << std::endl;
        std::cout << "AVL Insert Time (2 million): " << avl2Mil_insert << " nanoseconds" << std::endl;
        std::cout << "LL Append Time (2 million): " << LL2Mil_insert << " nanoseconds" << std::endl;
        std::cout << std::endl;
        
        //TODO: SEARCH OUTPUT
        std::cout << std::endl;
        std::cout << "BST Search Time (2 million): " << "Number: " << target2M << " Found: " << bstfound << " Time: " << bst2M_search << " nanoseconds" << std::endl;
        std::cout << "AVL Search Time (2 million): " << "Number: " << target2M << " Found: " << avlfound << " Time: " << avl2M_search << " nanoseconds" << std::endl;
        std::cout << "LL Search Time (2 million): " << "Number: " << target2M << " Found: " << LLfound << " Time: " << LL2M_search << " nanoseconds" << std::endl;
        std::cout << std::endl;

    std::cout << "====== BENCHMARK: 3,000,000  ======" << std::endl;

        std::vector<int> rand3Mil = GenerateRand(3000000); //generate numbers

        //INSERTIONS
        //BST
        BST bst3Mil; //create an instance of BST
        double bst3Mil_insert = benchmarkInsertion(bst3Mil, rand3Mil);
        //AVL
        AVL avl3Mil;
        double avl3Mil_insert = benchmarkInsertion(avl3Mil, rand3Mil);
        //LL
        LinkedList LL3Mil;
        double LL3Mil_insert  = benchmarkInsertion(LL3Mil, rand3Mil);

        //SEARCH
        int target3M = RNG();

        //BST
        double bst3M_search = benchmarkSearch(bst3Mil, target3M, bstfound);

        //AVL 
        double avl3M_search = benchmarkSearch(avl3Mil, target3M, avlfound);

        //LL
        double LL3M_search = benchmarkSearch(LL3Mil, target3M, LLfound);


        //INSERTION OUTPUT
        std::cout << std::endl;
        std::cout << "BST Insert Time (2 million): " << bst3Mil_insert << " nanoseconds" << std::endl;
        std::cout << "AVL Insert Time (2 million): " << avl3Mil_insert << " nanoseconds" << std::endl;
        std::cout << "LL Append Time (2 million): " << LL3Mil_insert << " nanoseconds" << std::endl;
        std::cout << std::endl;
        
        //TODO: SEARCH OUTPUT
        std::cout << std::endl;
        std::cout << "BST Search Time (2 million): " << "Number: " << target3M << " Found: " << bstfound << " Time: " << bst3M_search << " nanoseconds" << std::endl;
        std::cout << "AVL Search Time (2 million): " << "Number: " << target3M << " Found: " << avlfound << " Time: " << avl3M_search << " nanoseconds" << std::endl;
        std::cout << "LL Search Time (2 million): " << "Number: " << target3M << " Found: " << LLfound << " Time: " << LL3M_search << " nanoseconds" << std::endl;
        std::cout << std::endl;
        
    std::cout << "====== BENCHMARK: 10,000 ASC  ======" << std::endl;

        std::vector<int> asc10k = GenerateASC(10000); //generate numbers

        //INSERTIONS
        //BST
        BST bst10k; //create an instance of BST
        double bst10k_insert = benchmarkInsertion(bst10k, asc10k);
        //AVL
        AVL avl10k;
        double avl10k_insert = benchmarkInsertion(avl10k, asc10k);
        //LL
        LinkedList LL10k;
        double LL10k_insert  = benchmarkInsertion(LL10k, asc10k);

        //SEARCH
        int target10k = RNG();

        //BST
        double bst10k_search = benchmarkSearch(bst10k, target10k, bstfound);

        //AVL 
        double avl10k_search = benchmarkSearch(avl10k, target10k, avlfound);

        //LL
        double LL10k_search = benchmarkSearch(LL10k, target10k, LLfound);

        //INSERTION OUTPUT
        std::cout << std::endl;
        std::cout << "BST Insert Time (10 thousand): " << bst10k_insert << " nanoseconds" << std::endl;
        std::cout << "AVL Insert Time (10 thousand): " << avl10k_insert << " nanoseconds" << std::endl;
        std::cout << "LL Append Time (10 thousand): " << LL10k_insert << " nanoseconds" << std::endl;
        std::cout << std::endl;
        
        //SEARCH OUTPUT
        std::cout << std::endl;
        std::cout << "BST Search Time (10 thousand): " << "Number: " << target10k << " Found: " << bstfound << " Time: " << bst10k_search << " nanoseconds" << std::endl;
        std::cout << "AVL Search Time (10 thousand): " << "Number: " << target10k << " Found: " << avlfound << " Time: " << avl10k_search << " nanoseconds" << std::endl;
        std::cout << "LL Search Time (10 thousand): " << "Number: " << target10k << " Found: " << LLfound << " Time: " << LL10k_search << " nanoseconds" << std::endl;
        std::cout << std::endl;
    std::cout << "====== BENCHMARK: 10,000 DESC ======" << std::endl;
        
        std::vector<int> desc10k = GenerateDESC(10000); //generate numbers

        //INSERTIONS
        //BST
        BST bst10kD; //create an instance of BST
        double bst10kD_insert = benchmarkInsertion(bst10kD, desc10k);
        //AVL
        AVL avl10kD;
        double avl10kD_insert = benchmarkInsertion(avl10kD, desc10k);
        //LL
        LinkedList LL10kD;
        double LL10kD_insert  = benchmarkInsertion(LL10kD, desc10k);

        //SEARCH
        int target10kD = RNG();

        //BST
        double bst10kD_search = benchmarkSearch(bst10kD, target10kD, bstfound);

        //AVL 
        double avl10kD_search = benchmarkSearch(avl10kD, target10kD, avlfound);

        //LL
        double LL10kD_search = benchmarkSearch(LL10kD, target10kD, LLfound);

        //INSERTION OUTPUT
        std::cout << std::endl;
        std::cout << "BST Insert Time (10 thousand): " << bst10kD_insert << " nanoseconds" << std::endl;
        std::cout << "AVL Insert Time (10 thousand): " << avl10kD_insert << " nanoseconds" << std::endl;
        std::cout << "LL Append Time (10 thousand): " << LL10kD_insert << " nanoseconds" << std::endl;
        std::cout << std::endl;
        
        //SEARCH OUTPUT
        std::cout << std::endl;
        std::cout << "BST Search Time (10 thousand): " << "Number: " << target10kD << " Found: " << bstfound << " Time: " << bst10kD_search << " nanoseconds" << std::endl;
        std::cout << "AVL Search Time (10 thousand): " << "Number: " << target10kD << " Found: " << avlfound << " Time: " << avl10kD_search << " nanoseconds" << std::endl;
        std::cout << "LL Search Time (10 thousand): " << "Number: " << target10kD << " Found: " << LLfound << " Time: " << LL10kD_search << " nanoseconds" << std::endl;
        std::cout << std::endl;

    return 0;
}

std::vector<int> GenerateRand(size_t size)
{
    std::vector<int> data;
    data.reserve(size); // pre allocate memory

    //using a seed to generate random numbers 
    std::mt19937 rng(47); 
    std::uniform_int_distribution<int> dist(1,3000000);
    
    for (int i = 1; i <= size; ++i)
    {
        data.push_back(dist(rng));
    }
    return data;
}
std::vector<int> GenerateASC(size_t size)
{

    std::vector<int> ASC_Sequence;
    ASC_Sequence.reserve(size);
    int N = size; 
    
  

  for (int i = 1; i <= N; ++i)
  {
    ASC_Sequence.push_back(i);
  }
  return ASC_Sequence;
}
std::vector<int> GenerateDESC(size_t size)
{
    std::vector<int> DESC_Sequence; 
    DESC_Sequence.reserve(size);
    int N = size;
    for (int i = N; i >= 1; --i)
    {
        DESC_Sequence.push_back(i);
    }
    return DESC_Sequence;
}

int RNG()
{
    std::random_device rd;
    static std::mt19937 rng(rd());
    static std::uniform_int_distribution<int> dist(1,3000000); 

    
    return dist(rng);
}