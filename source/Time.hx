package;

class Time{
	private var pace:Int;
	private var cpu_time:Int;
	private var day:Int;
	private var year:Int;
	private var month_no:Int;		
    private var month:String;
	public var total_days:Int;	            
    public var calendar_day:String;

 	private var months : Array<String> = ["January","February","March","April","May","June","July","August","September","October","November","December"];
 	private var month_days : Array<Int> = [31,28,31,30,31,30,31,31,30,31,30,31];

	public function new(d, m, y, p){
	    day = d;
	    month = m;
	    year = y;
	    pace = p;
	    total_days = 0;	
	    cpu_time = 0;
	    for(i in 0...11){
	        if(m == months[i]){
	            month_no = i;
	            break;
	        }
	    }
	} 

	public function update(){
	    cpu_time++;	
	    if(cpu_time%pace==0)
	    	update_day();	
	} 	

	public function update_day(){
	    if(day==month_days[month_no]&&month_no==11){
	        day=1;
	        month_no=0;
	        year++;
	        month=months[0];
	    }
	    else if(day>=month_days[month_no]){
	        if(month_no==1&&year%4==0&&day==28){
	            day++;
	        }
	        else{
	            day=1;
	            month_no++;
	            month=months[month_no];
	        }
	    }
	    else{
	        day++;
	    }
	    total_days++;	
	    calendar_day = get_calendar_day();	
	} 	

	private function get_calendar_day():String{
	    return day + " " + month + " " + year;	
	} 	   
}