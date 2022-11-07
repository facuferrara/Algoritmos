#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;
/**
 * @author raidentrance
 *
 */
class GraphOri 
{
    list<NodeOri> nodes;
 
    void addNode(NodeOri node) 
    {
        if (nodes == null) 
        {
            nodes = new ArrayList<>();
        }
        nodes.add(node);
    }
 
    list<NodeOri> getNodes() 
    {
        return nodes;
    }
 
    @Override
    string toString() 
    {
        return "Graph [nodes=" + nodes + "]";
    }
 
}