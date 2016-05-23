double getBallVolume (double r) { return pi * 4 * pow(r, 3) / 3; }
double getBallArea (double r) { return pi * 4 * pow(r, 2); }
double getBallLength (double lat1, double lot1, double lat2, double lot2, double r) {
	double dlot = lot2 - lot1;
	double dlat = lat2 - lat1;
	double a = pow(sin(dlat/2), 2) + cos(lat1)*cos(lat2)*pow(sin(dlot/2), 2);
	double c = 2 * atan2(sqrt(a), sqrt(1-a));
	return c * r;
}

