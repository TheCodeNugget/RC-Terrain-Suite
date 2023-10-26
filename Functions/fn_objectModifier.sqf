params ["_mode"];

switch (_mode) do {
	case 1: {
		do3DENAction "SnapToSurface";
		["RnCTS_snapped", 3] call BIS_fnc_3DENNotification;
	};
	
	case 2: {
		do3DENAction "LevelOutObjects";
		["RnCTS_seaOriented", 3] call BIS_fnc_3DENNotification;
	};
	
	case 3: {
		do3DENAction "LevelWithSurface";
		["RnCTS_groundOriented", 3] call BIS_fnc_3DENNotification;
	};
	
	case 4: {
		do3DENAction "OpenAttributes";
	};
	
	case 5: {
		_increment = get3DENGrid "r";
		_objects = get3DENSelected "object";
		{
			_angle = (_x get3DENAttribute "rotation") # 0;
			_angle set [2, (_angle # 2) + _increment];
			_x set3DENAttribute ["rotation", _angle];
		} forEach _objects;
	};
	
	case 6: {
		_increment = get3DENGrid "r";
		_objects = get3DENSelected "object";
		{
			_angle = (_x get3DENAttribute "rotation") # 0;
			_angle set [2, (_angle # 2) - _increment];
			_x set3DENAttribute ["rotation", _angle];
		} forEach _objects;
	};
};
