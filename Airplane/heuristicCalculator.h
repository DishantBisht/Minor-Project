double heuristicCalculator(double lat1, double lon1, double lat2, double lon2){  
    double theta, dist;
    if ((lat1 == lat2) && (lon1 == lon2)) {
        return 0;
    }
    else {
        theta = lon1 - lon2;
        dist = sin(degToRad(lat1)) * sin(degToRad(lat2)) + cos(degToRad(lat1)) * cos(degToRad(lat2)) * cos(degToRad(theta));
        dist = acos(dist);
        dist = radToDeg(dist);
        dist = dist * 60 * 1.1515 * 1.609344;
        double heu = (dist/926)*60;
        return (heu);
    }
}