# EE538 Final Project - Fall 2021 - TrojanMap


## TrojanMap


### Author: Zixu Wang, Bin Ma

This project focuses on using data structures in C++ and implementing various graph algorithms to build a map application.

<p align="center"><img src="img/TrojanMap.png" alt="Trojan" width="500" /></p>

- Please clone the repository, look through [README.md](README.md) and fill up functions to finish in the project.
- Please make sure that your code can run `bazel run/test`.
- In this project, you will need to fill up [trojanmap.cc](src/lib/trojanmap.cc) and add unit tests in the `tests` directory.

---

## The data Structure

Each point on the map is represented by the class **Node** shown below and defined in [trojanmap.h](src/lib/trojanmap.h).

```cpp
class Node {
  public:
    std::string id;    // A unique id assign to each point
    double lat;        // Latitude
    double lon;        // Longitude
    std::string name;  // Name of the location. E.g. "Bank of America".
    std::vector<std::string>
        neighbors;  // List of the ids of all neighbor points.
};

```

---

## Prerequisites

### OpenCV Installation

For visualization, we use OpenCV library. You will use this library as a black box and don't need to worry about the graphic details.

Use the following commands to install OpenCV.

```shell
$ cd 2021Fall_TrojanMap
$ git clone https://github.com/opencv/opencv.git
```

### Other library Installations

For Ubuntu:
```shell
$ sudo apt-get install cmake libgtk2.0-dev pkg-config
$ sudo apt install libcanberra-gtk-module libcanberra-gtk3-module
$ sudo apt-get install libncurses5-dev libncursesw5-dev
$ cp ubuntu/* ./
```

For MacOS:
```shell
$ brew install cmake
$ brew install ncurses
```

Next, type the following, but make sure that you set the **path_to_install_folder** to be the absolute path to the install folder under opencv.

```shell
$ cd opencv/
$ mkdir build install
$ cd build
$ cmake -D CMAKE_INSTALL_PREFIX=/Users/binma/USC_EE/EE538/final-project-BinkMa/opencv/install\
 -D BUILD_LIST=core,highgui,imgcodecs,imgproc,videoio\
 -D WITH_TBB=ON -D WITH_OPENMP=OFF -D WITH_IPP=ON\
 -D CMAKE_BUILD_TYPE=RELEASE -D BUILD_EXAMPLES=OFF\
 -D WITH_NVCUVID=ON\
 -D WITH_CUDA=ON\
 -D BUILD_DOCS=OFF\
 -D BUILD_PERF_TESTS=OFF\
 -D BUILD_TESTS=OFF\
 -D WITH_CSTRIPES=ON\
 -D WITH_OPENCL=ON ..
$ make install
```

For example, if cloned this repo under "/Users/ari/github/TrojanMap", you should type:

```shell
$ cd opencv/
$ mkdir build install
$ cd build
$ cmake -D CMAKE_INSTALL_PREFIX=/Users/ari/github/TrojanMap/opencv/install\
 -D BUILD_LIST=core,highgui,imgcodecs,imgproc,videoio\
 -D WITH_TBB=ON -D WITH_OPENMP=ON -D WITH_IPP=ON\
 -D CMAKE_BUILD_TYPE=RELEASE -D BUILD_EXAMPLES=OFF\
 -D WITH_NVCUVID=ON\
 -D WITH_CUDA=ON\
 -D BUILD_DOCS=OFF\
 -D BUILD_PERF_TESTS=OFF\
 -D BUILD_TESTS=OFF\
 -D WITH_CSTRIPES=ON\
 -D WITH_OPENCL=ON ..
$ make install
```

---

## Run the program

Please run:

```shell
$ bazel run src/main:main
```

If everything is correct, this menu will show up.

```shell
Torjan Map
**************************************************************
* Select the function you want to execute.                    
* 1. Autocomplete                                             
* 2. Find the position                                        
* 3. CalculateShortestPath                                    
* 4. Travelling salesman problem                              
* 5. Cycle Detection                                          
* 6. Topological Sort                                         
* 7. Find K Closest Points                                    
* 8. Exit                                                     
**************************************************************
Please select 1 - 8:
```

## Test the program

We created some tests for you to test your program, please run
```shell
$ bazel test tests:trojanmap_test
```

Please add you test in the [trojanmap_test_student.cc](tests/trojanmap_test_student.cc) and run

```shell
$ bazel test tests:trojanmap_test_student
```

## First task is to implement a function for each menu item

## Step 1: Autocomplete the location name

```c++
std::vector<std::string> Autocomplete(std::string name);
```

We consider the names of nodes as the locations. Implement a method to type the partial name of the location and return a list of possible locations with partial name as prefix. Please treat uppercase and lower case as the same character.

Example:

Input: "ch" \
Output: ["ChickfilA", "Chipotle Mexican Grill"]

Input: "ta" \
Output: ["Target", "Tap Two Blue"]

```shell
1
**************************************************************
* 1. Autocomplete                                             
**************************************************************

Please input a partial location:ch
*************************Results******************************
ChickfilA
Chipotle Mexican Grill
**************************************************************
Time taken by function: 315  microseconds
```
<p align="center"><img src="img/autocomplete.png" alt="autocomplete" width="300"/></p>

  ```c++
  for (auto it=data.begin();it!=data.end();it++){

      for(int i=0;i<name.length();i++){
      }
  }
  ```
Time complexity: O(n*l),
n is the number of vertices in self.data, l is the length of a node name 


## Step 2: Find the place's Coordinates in the Map

```c++
std::pair<double, double> GetPosition(std::string name);
```

Given a location name, return the latitude and longitude. There are no duplicated location names. You should mark the given locations on the map. If the location does not exist, return (-1, -1).

Example:

Input: "ChickfilA" \
Output: (34.0167334, -118.2825307)

Input: "Ralphs" \
Output: (34.0317653, -118.2908339)

Input: "Target" \
Output: (34.0257016, -118.2843512)

```shell
2
**************************************************************
* 2. Find the position                                        
**************************************************************

Please input a location:Target
*************************Results******************************
Latitude: 34.0257 Longitude: -118.284
**************************************************************
Time taken by function: 292 microseconds
```

<p align="center"><img src="img/Target.png" alt="Target" width="500"/></p>
<p align="center"><img src="img/getposition.png" alt="getposition" width="300"/></p>

```c++
std::pair<double, double> TrojanMap::GetPosition(std::string name) {
  for(auto it=data.begin();it!=data.end();it++){

  }
```


Please input a location:Target
*************************Results******************************
Latitude: 34.0257 Longitude: -118.284
**************************************************************
Time taken by function: 292 microseconds

Please input a location:Ralphs
*************************Results******************************
Latitude: 34.0318 Longitude: -118.291
**************************************************************
Time taken by function: 296 microseconds

Time complexity: O(n),
n is the number of nodes in self.data 

## Step 3: CalculateShortestPath between two places

```c++
std::vector<std::string> CalculateShortestPath_Dijkstra(std::string &location1_name,
                                               std::string &location2_name);
std::vector<std::string> CalculateShortestPath_Bellman_Ford(std::string &location1_name,
                                               std::string &location2_name);
```

Given 2 locations A and B, find the best route from A to B. The distance between 2 points is the euclidean distance using latitude and longitude. You should use both Dijkstra algorithm and Bellman-Ford algorithm. Compare the time for the different methods. Show the routes on the map. If there is no path, please return empty vector.

Please report and compare the time spent by these 2 algorithms.

Example:

Input: "Ralphs", "ChickfilA" \
Output: ["2578244375", "5559640911", "6787470571", "6808093910", "6808093913", "6808093919", "6816831441",
      "6813405269", "6816193784", "6389467806", "6816193783", "123178876", "2613117895", "122719259",
      "2613117861", "6817230316", "3642819026", "6817230310", "7811699597", "5565967545", "123318572",
      "6813405206", "6813379482", "544672028", "21306059", "6813379476", "6818390140", "63068610", 
      "6818390143", "7434941012", "4015423966", "5690152766", "6813379440", "6813379466", "21306060",
      "6813379469", "6813379427", "123005255", "6807200376", "6807200380", "6813379451", "6813379463",
      "123327639", "6813379460", "4141790922", "4015423963", "1286136447", "1286136422", "4015423962",
      "6813379494", "63068643", "6813379496", "123241977", "4015372479", "4015372477", "1732243576",
      "6813379548", "4015372476", "4015372474", "4015372468", "4015372463", "6819179749", "1732243544",
      "6813405275", "348121996", "348121864", "6813405280", "1472141024", "6813411590", "216155217", 
      "6813411589", "1837212103", "1837212101", "6820935911", "4547476733"]

```shell
3
**************************************************************
* 3. CalculateShortestPath
**************************************************************

```

<p align="center"><img src="img/Routing.png" alt="Routing" width="500"/></p>
<p align="center"><img src="img/Dijkstra.png" alt="Dijkstra" width="300"/></p>


Please input the start location:Ralphs
Please input the destination:ChickfilA
*************************Results******************************
The distance of the path is:1.53852 miles
**************************************************************
Time taken by function: 44364 microseconds

Please input the start location:Ralphs
Please input the destination:Target
*************************Results******************************
The distance of the path is:0.839235 miles
**************************************************************
Time taken by function: 18839 microseconds

```c++
std::vector<std::string> TrojanMap::CalculateShortestPath_Dijkstra(
    std::string location1_name, std::string location2_name) {
    while(!q.empty()){
      if(curr != end){
        for(auto neighbor:data[curr].neighbors){

        }
      }}
    }
```
Time complexity: O(n + m*log(m)),
n is the number of nodes in self.data, m is the number of edges (paths) 

<p align="center"><img src="img/Bellman_ford.png" alt="Bellman_ford" width="300"/></p>


Please input the start location:Ralphs
Please input the destination:ChickfilA
*************************Results******************************
The distance of the path is:1.53852 miles
**************************************************************
Time taken by function: 64629785 microseconds

Please input the start location:Ralphs
Please input the destination:Target
*************************Results******************************
The distance of the path is:0.839235 miles
**************************************************************
Time taken by function: 60059642 microseconds

```c++
std::vector<std::string> TrojanMap::CalculateShortestPath_Bellman_Ford(
    std::string location1_name, std::string location2_name){

for (int i = 0; i < data.size()-1; i++){
    for (auto pair: data){
    //  std::string cur = pair.first;
      for (auto neighbor: pair.second.neighbors){
      }
      }
   }
```

Time complexity: O(n*m),
where n is the number of nodes in data, m is the number of edges .




## Step 4: The Traveling Trojan Problem (AKA Traveling Salesman!)

In this section, we assume that a complete graph is given to you. That means each node is a neighbor of all other nodes.
Given a vector of location ids, assume every location can reach all other locations in the vector (i.e. assume that the vector of location ids is a complete graph).
Find the shortest route that covers all the locations exactly once and goes back to the start point. 

You will need to return the progress to get the shortest route which will then be converted to an animation.  

We will use the following algorithms:

- Backtracking
```c++
std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan(
      std::vector<std::string> &location_ids);
```
- [2-opt Heuristic](https://en.wikipedia.org/wiki/2-opt). Also see [this paper](http://cs.indstate.edu/~zeeshan/aman.pdf)
```c++
std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan_2opt(
      std::vector<std::string> &location_ids);
```

Please report and compare the time spent by these 2 algorithms. 2-opt algorithm may not get the optimal solution. Please show how far your solution is from the optimal solution.

Show the routes on the map. For each intermediate solution, create a new plot. Your final video presentation should include the changes to your solution.

We will randomly select N points in the map and run your program.

```shell
4
**************************************************************
* 4. Travelling salesman problem                              
**************************************************************

In this task, we will select N random points on the map and you need to find the path to travel these points and back to the start point.

Please input the number of the places:10
Calculating ...
*************************Results******************************
The distance of the path is:4.70299 miles
**************************************************************
You could find your animation at src/lib/output.avi.          
Time taken by function: 152517394 microseconds
```

<p align="center"><img src="img/TSP.png" alt="TSP" width="500"/></p>

<p align="center"><img src="img/output.gif" alt="TSP videos" width="500"/></p>

<p align="center"><img src="img/traveling.png" alt="traveling" width="300"/></p>

```c++
std::pair<double, std::vector<std::vector<std::string>>> TrojanMap::TravellingTrojan(std::vector<std::string> &location_ids) {
  
}
void TrojanMap::TSP_aux(std::vector<std::string> &ids, std::vector<std::vector<std::string>> &paths, 
                        std::vector<std::string> &curPath, double &curDis, double &minDis){                
     for (int i = 1; i < ids.size(); i++) {
       TSP_aux(ids, paths, curPath, curDis, minDis);
     }                     
  }
```
Please input the number of the places:10
Calculating ...
*************************Results******************************
The distance of the path is:4.70299 miles
**************************************************************
You could find your animation at src/lib/output.avi.          
Time taken by function: 761572 microseconds

Solving TSP with backtracking
Time complexity:  O((n-1)!),
where n is the number of nodes in self.data


<p align="center"><img src="img/2opt.png" alt="2opt" width="500"/></p>

```c++
std::pair<double, std::vector<std::vector<std::string>>> TrojanMap::TravellingTrojan_2opt(std::vector<std::string> &location_ids){
     while(improving){
        for (int i = 1; i <= n - 2; i++) {
            for (int k = i+1 ; k<= n - 1; k++) {
            }
        }
     }
}
```

**************************************************************
The distance of the path is:3.68783 miles
**************************************************************
You could find your animation at src/lib/output.avi.          
Time taken by function: 4805 microseconds

Solving TSP with 2-opt
Time complexity:  O(n^2),
where n is the number of nodes in self.data

## Step 5: Cycle Detection

```c++
bool CycleDetection(std::vector<double> &square);
```

In this section, we use a square-shaped subgraph of the original graph by using four coordinates stored in ```std::vector<double> square```, which follows the order of left, right, upper, and lower bounds. 

Then try to determine if there is a cycle path in the that subgraph. If it does, return true and report that path on the map. Otherwise return false.

Example 1:
```shell
Input: square = {-118.299, -118.264, 34.032, 34.011}
Output: true
```
Here we use the whole original graph as our subgraph. 
<p align="center"><img src="img/cycle1.png" alt="TSP" width="500"/></p>

Example 2:
```shell
Input: square = {-118.290919, -118.282911, 34.02235, 34.019675}
Output: false
```
Here we use a square area inside USC campus as our subgraph
<p align="center"><img src="img/cycle2.png" alt="TSP" width="500"/></p>

Note: You could use the function below to visualize the subgraph. 

```c++
/**
 * PlotPoints: Given a vector of location ids draws the points on the map (no path).
 * 
 * @param  {std::vector<std::string>} location_ids : points inside square
 * @param  {std::vector<double>} square : boundary
 */
void TrojanMap::PlotPointsandEdges(std::vector<std::string> &location_ids, std::vector<double> &square)
```
```shell
5
**************************************************************
* 5. Cycle Detection                                          
**************************************************************
Please input the left bound longitude(between -118.299 and -118.264):-118.299
Please input the right bound longitude(between -118.299 and -118.264):-118.264
Please input the upper bound latitude(between 34.011 and 34.032):34.032
Please input the lower bound latitude(between 34.011 and 34.032):34.011
*************************Results******************************
there exists cycle in the subgraph 
**************************************************************
Time taken by function: 9470 microseconds
```


<p align="center"><img src="img/cycle.png" alt="cycle" width="300"/></p>

```c++
bool CycleDetection(std::vector<double> &square){
  for(auto node_id :Node_ids){
     ...;
     if(IsCycleUtil(node_id, visited, prev, cycle_path)==true) return true;  
  }
}
bool TrojanMap::IsCycleUtil(std::string node_id, std::map<std::string, bool> &visited ,std::string prev, std::vector<std::string> &cycle_path){

  for(auto neighbor: data[node_id].neighbors){

  }
```
Time complexity: O(m+n),
n is the number of location ids in the data, m is the number of edges.

## Step 6: Topological Sort

```c++
std::vector<std::string> DeliveringTrojan(std::vector<std::string> &location_names,
                                            std::vector<std::vector<std::string>> &dependencies);
```

Tommy Trojan got a part-time job from TrojanEats, for which he needs to pick up and deliver food from local restaurants to various location near the campus. Tommy needs to visit a few different location near the campus with certain order, since there are some constraints. For example, he must first get the food from the restaurant before arriving at the delivery point. 

The TrojanEats app will have some instructions about these constraints. So, Tommy asks you to help him figure out the feasible route!

Here we will give you a vector of location names that Tommy needs to visit, and also some dependencies between those locations.


For example, 

```shell
Input: 
location_names = {"Cardinal Gardens", "Coffee Bean1", "CVS"}
dependencies = {{"Cardinal Gardens","Coffee Bean1"}, {"Cardinal Gardens","CVS"}, {"Coffee Bean1","CVS"}}
```

Here, ```{"Cardinal Gardens","Coffee Bean1"}``` means
that Tommy must go to `Cardinal Gardens` prior to `Coffee Bean1`.

Your output should be:
```shell
Output: Cardinal Gardens -> Coffee Bean1 -> CVS
```
Also, we provide ```PlotPointsOrder``` function that can visualize the results on the map. It will plot each location name and also some arrowed lines to demonstrate a feasible route.

If no feasible route exists, you could simply return an empty vector.

Hint:
- You also need to finish ```ReadLocationsFromCSVFile``` and ```ReadDependenciesFromCSVFile``` functions, so you could read and parse data from you own CSV files. We also give two sample CSV files under ```input``` folder, which could be a reference. 
- When it asks you filenames, you need to give the absolute path.
- If you do not have ```ReadLocationsFromCSVFile``` and ```ReadDependenciesFromCSVFile``` functions ready yet, you can just press enter when it asks you filenames. It will call the default locations and dependencies.
- The locations are actually nodes, and the dependencies could be directed edges. You may want to first construct a DAG and then implement topological sort algorithm to get the route.

```shell
6
*************************Results******************************
Topological Sorting Results:
Cardinal Gardens
Coffee Bean1
CVS
**************************************************************
Time taken by function: 43 microseconds
```
<p align="center"><img src="img/TopologicalSort.png" alt="TSP" width="500"/></p>

In the user interface, we read the locations and dependencies from `topologicalsort_dependencies.csv` and `topologicalsort_locations.csv` to modify your input there.

Please input the locations filename:/Users/binma/USC_EE/EE538/final-project-BinkMa/input/topologicalsort_locations.csv
Please input the dependencies filename:/Users/binma/USC_EE/EE538/final-project-BinkMa/input/topologicalsort_dependencies.csv
*************************Results******************************
Topological Sorting Results:
Cardinal Gardens
Coffee Bean1
CVS
**************************************************************
Time taken by function: 58 microseconds

<p align="center"><img src="img/delivering.png" alt="delivering" width="300"/></p>

```c++
vector<string> TrojanMap::DeliveringTrojan(vector<string> &locations, vector<vector<string>> &dependencies)
  for(auto root: roots){
    DFS_helper_with_topo(root, visited, depend_map,result);
  }

void TrojanMap::DFS_helper_with_topo(std::string root, std::map<std::string, int> &visited,std::unordered_map<std::string, 
std::vector<std::string>> &depend_map,std::vector<std::string> &result){
    for(auto child: depend_map[root]){

    }
}

```

DFS is used for topological sort.

Time complexity: O(m+n), 
n is the number of nodes data, m is the number of edges.


## Step 7: Find K closest points

Given a location name and a integer k , find the k closest locations with name on the map and return a vector of string ids. 

We will use the following algorithms:

- Backtracking
```c++
std::vector<std::string> FindKClosestPoints(std::string name, int k);
```

Please report and compare the time spent by this algorithm and show the points on the map.

```shell

**************************************************************
* 7. Find K Closest Points                                    
**************************************************************

Result:

Please input the locations:Raphls
Please input k:10
*************************Results******************************
Find K Closest Points Results:
1 FootballSoccer Field
2 Hill 38 Washington
3 61
4 Historic SouthCentral
5 Tap Two Blue
6 Aldewaniah
7 23rd Street
8 Los Angeles Orthopaedic Hospital
9 John Adams Middle School
10 LATTCOrtho Institute
**************************************************************
Time taken by function: 2673 microseconds
```

<p align="center"><img src="img/Kclosest.png" alt="Kclosest" width="500"/></p>

<p align="center"><img src="img/KNN.png" alt="KNN" width="300"/></p>

```c++
std::vector<std::string> FindKClosestPoints(std::string name, int k){
  for(auto nodes_obj:data){
    if(nodes_obj.second.name.size()!=0 && nodes_obj.second.name!=name){
    }
  }
}
```

Time complexity: O(n), 
n is the number of nodes data。


Conclusion: 

In this final project,  we mainly focus on the implementation of graph algorithms. From the most basic c++ syntax, to data structures, depth-first search algorithms, breadth-first search algorithms, backtracking algorithms, we have applied them all in this project.

This project gave us initial experience in writing C++ projects, and at the same time gave us a deeper understanding of the features of C++, which is very helpful for our work and subsequent development。






