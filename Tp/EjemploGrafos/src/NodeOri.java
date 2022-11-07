	import java.util.ArrayList;
	import java.util.List;
	 
	/**
	 * @author raidentrance
	 *
	 */
	public class NodeOri 
	{
	    private String city;
	    private List<EdgeOri> edges;
	 
	    public NodeOri(String city) 
	    {
	        this.city = city;
	    }
	 
	    public String getCity() 
	    {
	        return city;
	    }
	 
	    public void setCity(String city) 
	    {
	        this.city = city;
	    }
	 
	    public List<EdgeOri> getEdges() 
	    {
	        return edges;
	    }
	 
	    public void addEdge(EdgeOri edge) 
	    {
	        if (edges == null) 
	        {
	            edges = new ArrayList<>();
	        }
	        edges.add(edge);
	    }
	 
	    @Override
	    public String toString() 
	    {
	        return "\n \tNode [city=" + city + ", edges=" + edges + "]";
	    }
	}

