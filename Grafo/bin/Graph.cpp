#include<iostream>
#include<list>
using namespace std;
 
/**
 * @author raidentrance
 *
 */
template <typename T>
class Graph 
{
 
    private List<NodeOri> nodes;
 
    public void addNode(NodeOri node) 
    {
        if (nodes == null) 
        {
            nodes = new ArrayList<>();
        }
        nodes.add(node);
    }
 
    public List<NodeOri> getNodes() 
    {
        return nodes;
    }
 
    // @Override
    public String toString() 
    {
        return "Graph [nodes=" + nodes + "]";
    }
 
};