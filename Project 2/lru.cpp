#include <vector>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <fstream>

//struct to store page info
struct page {
    std::string address;
    char rw;
};

//data structures used
std::vector<page> cache; // will be holding pages
std::vector<std::string> disk; // will be save the pages into disk that have 'W'


//counter variables
int rCount=0,wCount=0,size=0;//Counts for each read/write into disk, and size of cache limit
int hitCount=0,faultCount=0;//Counts for each page hit/fault
int traceCount;//total frame entries



int nFrames=0;//variable to store total number of frames
std::string mode;//store mode (debug/quiet)


//function to print cache contents
void printCache(){
    for(auto it= cache.begin();it!=cache.end();it++){
     std::cout<< (*it).address <<' '<< (*it).rw << std::endl;
   }   
}




// function purpose: insert pages at beginning of cache for most recent use, and remove from end of cache if least recently used
void refer(struct page p, std::string mode){

    //loop through cache
    auto i = cache.begin();
    for (i = cache.begin(); i != cache.end(); ++i){
        if((*i).address==p.address) break;//iterator stops if it finds page
    }
    
    if(i != cache.end()){ // if iterator did not reach the end then page has been found in cache and it is a HIT
        
        //if page is being replaced is 'R' inside of cache but 'W' in trace, then push page with new status 'W'
        if((*i).rw=='R' && p.rw=='W'){
            (*i).rw='W';
            cache.insert(cache.begin(),*i);//insert to front of cache as most recent one
            cache.erase(i);        //remove old page
        }
        else if((*i).rw=='W'){//if page was already in write staus then just push it to the beginning and erase it
            cache.insert(cache.begin(),*i);//insert to front of cache as most recent one
            cache.erase(i);        //remove old page

        }
        //since page was found in cache, it is a hit
        if(strcmp(mode.c_str(),"debug")==0){
            (std::cout<<"Page hit"<<std::endl);
        }
        hitCount++;// increment page hits
    }    
    
    else{//  page is not in cache (fault)
            if(size==nFrames){// cache is full since its size is equal to number of frames
                if(cache.back().rw=='W'){//since page to be removed is dirty
                    wCount++;// increment Writes
                }

                cache.pop_back();//remove least recently used page from cache
                cache.insert(cache.begin(),p);//insert new page at front as most recent page
                rCount++;//increment read Count when new page is pushed to cache
            }
            else{//cache has space
            cache.insert(cache.begin(),p);//insert at beginning of vector
            rCount++;//increment read Count when new page is pushed to cache from trace file
            size++;//cache size increases
            }

            if(strcmp(mode.c_str(),"debug")==0){//since page was found not in cache, it is a page fault
            (std::cout<<"Page fault"<<std::endl);
            }               
            faultCount++;// increment page faults


    }
    traceCount++;//trace has been read, increment
}


int main(int agrc,char **argv){
    //parameters from command line
    std::ifstream inFile(argv[1]);//read trace file
    nFrames=atoi(argv[2]);//take no. of frames 
    mode=argv[3];//take mode:debug/quiet
    
    //Explaining status of program
    std::cout<<"Reading file: " << argv[1]<<std::endl;
    std::cout<<"Size of cache: " << argv[2]<<std::endl;
    std::cout<<"Mode: " << argv[3]<<std::endl;
    


    struct page p;// holds each page being read from file before referencing
    int i=0;
    while(inFile>>p.address>>p.rw){//file pointer starts at beginning of each line
            refer(p,mode);//page is referenced
    }


   printCache();
  
   //print stats
   std::cout<< "Total Memory Frames: " << nFrames<<std::endl;
   std::cout<< "In-trace Count: "<< traceCount << std::endl;
   std::cout<<"Total Disk Reads: "<< rCount << std::endl;
   std::cout<<"Total Disk Writes: "<< wCount << std::endl;
   std::cout<<"Total Page Hits: "<< hitCount << std::endl;
   std::cout<<"Total Page Faults: "<< faultCount << std::endl;
   std::cout<<"Hit rate: "<< float(hitCount)/float(traceCount) << std::endl;


}