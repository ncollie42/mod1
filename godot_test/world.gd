extends Spatial

func _ready():
	var scene = load("res://myGround.tscn")
	var node = scene.instance()
	add_child(node)
	

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	$Rotate.rotate_y(delta * 0.5)
	
