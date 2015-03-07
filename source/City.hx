package;

class City{	
    private var name:String;
	public var coordinate_x:Int;	            
	public var coordinate_y:Int;
	private var population_total:Int;
	private var population:Array<Int>;

	public function new(n, c_x, c_y, p){
	    name = n;
	    coordinate_x = c_x;
	    coordinate_y = c_y;
	    population = p.copy();
	} 

}