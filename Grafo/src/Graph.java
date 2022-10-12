import java.util.ArrayList;
import java.util.List;
 
/**
 * @author raidentrance
 *
 */
public class GraphOri 
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
 
    @Override
    public String toString() 
    {
        return "Graph [nodes=" + nodes + "]";
    }
 
}