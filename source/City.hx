package;

class City{	
    public var name:String;
	public var coordinate_x:Int;	            
	public var coordinate_y:Int;
	public var label_coordinate_x:Int;	            
	public var label_coordinate_y:Int;	
	private var population_total:Int;
	private var population:Array<Int>;

	public function new(n, c_x, c_y, p){
	    name = n;
	    coordinate_x = c_x;
	    coordinate_y = c_y;
	    population = p.copy();
	    label_coordinate_x = (c_x - 1) * PlayState.TILE_WIDTH;
	    label_coordinate_y = (c_y + 1) * PlayState.TILE_WIDTH;	    
	} 
}