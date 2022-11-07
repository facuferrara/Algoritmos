	import java.util.ArrayList;
	import java.util.List;
	 
	/**
	 * @author raidentrance
	 *
	 */
	public class Node 
	{
	    private String terminal;
	    private List<Terminal> terminal;
	 
	    public Node(String terminal) 
	    {
	        this.terminal = terminal;
	    }
	 
	    public String getterminal() 
	    {
	        return terminal;
	    }
	 
	    public void setterminal(String terminal) 
	    {
	        this.terminal = terminal;
	    }
	 
	    public List<Terminal> gettermis() 
	    {
	        return terminal;
	    }
	 
	    public void addTermi(Terminal termi) 
	    {
	        if (termi == null) 
	        {
	            termi = new ArrayList<>();
	        }
	        termi.add(terminal);
	    }
	 
	    @Override
	    public String toString() 
	    {
	        return "\n \tNode [terminal=" + terminal + ", termis=" + termis + "]";
	    }
	}

