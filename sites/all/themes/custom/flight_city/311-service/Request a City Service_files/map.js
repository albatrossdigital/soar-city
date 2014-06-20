
    var MAPFILES_URL = "http://maps.gstatic.com/intl/en_us/mapfiles/";

    var map = null;
    var geocoder = null;
    var shadow = null;
    var clickIcon = null;
    var clickMarker = null;
    var markers = null;
    var selected = null;
    var infowindow = null;
    var boundsOverlay = null;
    var viewportOverlay = null;
    var initialized = false;
    var hashFragment = "";

    var GeocoderStatusDescription = {
        "OK": "The request did not encounter any errors",
        "UNKNOWN_ERROR": "A geocoding or directions request could not be successfully processed, yet the exact reason for the failure is not known",
        "OVER_QUERY_LIMIT": "The webpage has gone over the requests limit in too short a period of time",
        "REQUEST_DENIED": "The webpage is not allowed to use the geocoder for some reason",
        "INVALID_REQUEST": "This request was invalid",
        "ZERO_RESULTS": "The request did not encounter any errors but returns zero results",
        "ERROR": "There was a problem contacting the Google servers"
    };

    var GeocoderLocationTypeDescription = {
        "ROOFTOP": "The returned result reflects a precise geocode.",
        "RANGE_INTERPOLATED": "The returned result reflects an approximation (usually on a road) interpolated between two precise points (such as intersections). Interpolated results are generally returned when rooftop geocodes are unavilable for a street address.",
        "GEOMETRIC_CENTER": "The returned result is the geometric center of a result such a line (e.g. street) or polygon (region).",
        "APPROXIMATE": "The returned result is approximate."
    }

    var showMarkerDialog = true;
    function init2(beginLat, beginLng, beginZoom) {
        showMarkerDialog = false;

        var mapOptions = {
            'zoom': (beginZoom), 
            'center': (new google.maps.LatLng(beginLat, beginLng)), 
            'mapTypeId': google.maps.MapTypeId.ROADMAP
            //'scaleControl': false,
            //'panControl': false,
            //'rotateControl': false,
            //'scrollwheel': false,
            //'streetViewControl': false,
            //'zoomControl': false,
            //'disableDefaultUI': true
        }
        map = new google.maps.Map(document.getElementById("map"), mapOptions);

        geocoder = new google.maps.Geocoder();

        infowindow = new google.maps.InfoWindow({
            'size': new google.maps.Size(292, 120)
        });

        shadow = new google.maps.MarkerImage(
            MAPFILES_URL + "shadow50.png",
            new google.maps.Size(37, 34),
            new google.maps.Point(0, 0),
            new google.maps.Point(10, 34)
        );

        clickIcon = new google.maps.MarkerImage(
            MAPFILES_URL + 'dd-start.png',
            new google.maps.Size(20, 34),
            new google.maps.Point(0, 0),
            new google.maps.Point(10, 34)
        );

        submitQuery2(); 
    }

    var cityConstraint = '';
    var cityConstraintEnabled = false;
    function init(beginLat, beginLng, beginZoom, city, constraintEnabled) {
        cityConstraint = city;
        cityConstraintEnabled = constraintEnabled;
    
        var params = parseUrlParams();
        var location = $('#Address_StreetAddress').val();
        var lCity = $('#Address_City').val();
        var lState = $('#Address_State').val();
        location = location + ", " + lCity + ", " + lState;

        var mapOptions = {
            'zoom': (params.zoom ? params.zoom : beginZoom), 
            'center': (params.center ? params.center : new google.maps.LatLng(beginLat, beginLng)),
            'mapTypeId': google.maps.MapTypeId.ROADMAP, 
            'scaleControl': true
        }
        map = new google.maps.Map(document.getElementById("map"), mapOptions);

        geocoder = new google.maps.Geocoder();

        infowindow = new google.maps.InfoWindow({
            'size': new google.maps.Size(292, 120)
        });

        shadow = new google.maps.MarkerImage(
            MAPFILES_URL + "shadow50.png",
            new google.maps.Size(37, 34),
            new google.maps.Point(0, 0),
            new google.maps.Point(10, 34)  
        );

        clickIcon = new google.maps.MarkerImage(
            MAPFILES_URL + 'dd-start.png',
            new google.maps.Size(20, 34),
            new google.maps.Point(0, 0),
            new google.maps.Point(10, 34)
        );

        google.maps.event.addListener(map, 'click', onClickCallback);

        if (location.length > 0) {
            submitQuery();
        }
    }

    function onClickCallback(event) {
        geocode({ 'latLng': event.latLng });
    }

    function parseUrlParams() {
        var params = {};
        return params;
    }

    function submitQuery2() {
        var query = $('#srlocation').html();
        query = $.trim(query);
        if (/\s*^\-?\d+(\.\d+)?\s*\,\s*\-?\d+(\.\d+)?\s*$/.test(query)) {
            var latlng = parseLatLng(query);
            if (latlng == null) {
                document.getElementById("query").value = "";
            } else {
                geocode({ 'latLng': latlng });
            }
        } else {
            geocode({ 'address': query });
        }
    }

    function commonLocationCheck(street) {
        if (street != null && street.length > 0) {
            var b1 = street.indexOf('[');
            var b2 = street.indexOf(']');
            var b3 = street.lastIndexOf('[');
            var b4 = street.lastIndexOf(']');
            if (b1 != -1 && b2 != -1 && b3 != -1 && b4 != -1) {
                var details = street.substr(0, b3);
                street = street.substr(b3 + 1, b4 - (b3 + 1));
                $('#Address_Details').val(details);
            }
            else {
                $('#Address_Details').val('');
            }
        }
        return street;
    }

    function crossStreetCheck(street) {
        if (street != null && street.length > 0) {
            var b1 = street.indexOf('@');
            street = street.replace("@", " & ");
        }
        return street;
    }
    
    function submitQuery() {
        var sAddress = document.getElementById("Address_StreetAddress").value;
        sAddress = commonLocationCheck(sAddress);
        sAddress = crossStreetCheck(sAddress);
        var sCity = document.getElementById("Address_City").value;
        var sState = document.getElementById("Address_State").value;
        var query = sAddress + ', ' + sCity + ', ' + sState;
        
        
        if (/\s*^\-?\d+(\.\d+)?\s*\,\s*\-?\d+(\.\d+)?\s*$/.test(query)) {
            var latlng = parseLatLng(query);
            if (latlng == null) {
                document.getElementById("query").value = "";
            } else {
                geocode({ 'latLng': latlng });
            }
        } else {
            geocode({ 'address': query });
        }
    }

    function geocode(request) {
        resetMap();
        if (geocoder != null) geocoder.geocode(request, showResults);
    }

    function parseLatLng(value) {
        value.replace('/\s//g');
        var coords = value.split(',');
        var lat = parseFloat(coords[0]);
        var lng = parseFloat(coords[1]);
        if (isNaN(lat) || isNaN(lng)) {
            return null;
        } else {
            return new google.maps.LatLng(lat, lng);
        }
    }

    function resetMap() {
        if (infowindow != null) infowindow.close();

        if (clickMarker != null) {
            clickMarker.setMap(null);
            clickMarker = null;
        }

        for (var i in markers) {
            markers[i].setMap(null);
        }

        markers = [];
        selected = null;
        clearBoundsOverlays();
    }

    function showResults(results, status) {
        var reverse = (clickMarker != null);

        if (!results) {
            alert("Geocoder did not return a valid response");
        } else {
            //document.getElementById("statusValue").innerHTML = status;
            //document.getElementById("statusDescription").innerHTML = GeocoderStatusDescription[status];
            //document.getElementById("responseInfo").style.display = "block";
            //document.getElementById("responseStatus").style.display = "block";

            if (status == google.maps.GeocoderStatus.OK) {
                plotMatchesOnMap(results, reverse);
            } else {
                if (!reverse) {
                    map.setCenter(new google.maps.LatLng(0.0, 0.0));
                    map.setZoom(1);
                }
            }
        }
    }

    function getData(type, addressComponents, useLongName) {
        var value = '';
        for (var i = 0; i < addressComponents.length; i++) {
            if (addressComponents[i].types[0] == type) {
                value = useLongName ? addressComponents[i].long_name : addressComponents[i].short_name;
                break;
            }
        }
        return value;
    }

    function plotMatchesOnMap(results, reverse) {

        markers = new Array(results.length);
        var resultsListHtml = "";

        var openInfoWindow = function(resultNum, result, marker) {
            return function() {
                if (selected != null) {
                    //document.getElementById('p' + selected).style.backgroundColor = "white";
                    clearBoundsOverlays();
                }

                map.fitBounds(result.geometry.viewport);

                var lType = result.geometry.location_type;
                if (lType == 'ROOFTOP' || lType == 'RANGE_INTERPOLATED' || lType == 'APPROXIMATE') {
                    var sNumber = getData('street_number', result.address_components, true); //result.address_components[0].long_name;
                    var sName = getData('route', result.address_components, true); //result.address_components[1].long_name;

                    var isIntersection = result.types[0];
                    if (isIntersection != null && isIntersection == 'intersection') {
                        var c1 = result.formatted_address.indexOf(',');
                        if (c1 > 0) {
                            sName = result.formatted_address.substr(0, c1);
                        }
                    }

                    var sCity = getData('locality', result.address_components, true); //result.address_components[2].long_name;
                    var sState = getData('administrative_area_level_1', result.address_components, false); //result.address_components[4].short_name;
                    var zip = getData('postal_code', result.address_components, true); //result.address_components[6].long_name;
                    var cityCheck = cityConstraint.toString().toUpperCase();
                    if (!cityConstraintEnabled ||
                        (cityConstraintEnabled && sCity.toString().toUpperCase() == cityCheck)) {
                        infowindow.setContent(getAddressComponentsHtml(result));
                        var address = sNumber + " " + sName;

                        //$('#Address_StreetAddress').val(address);
                        //$('#Address_City').val(sCity.toString().toUpperCase());
                        //$('#Address_State').val(sState.toString().toUpperCase());
                        setAddress(address, sCity, sState);

                        $('#Address_Zip').val(zip);
                        document.getElementById("responseInfo").style.display = "none";
                        document.getElementById("responseStatus").style.display = "none";
                    }
                    else {
                        var alert = '<br />The location selected is not permitted.  The location must be within ' + cityConstraint + '.';
                        document.getElementById("statusValue").innerHTML = result.formatted_address;
                        document.getElementById("statusDescription").innerHTML = alert;
                        document.getElementById("responseInfo").style.display = "block";
                        document.getElementById("responseStatus").style.display = "block";

                    }
                }

                if (showMarkerDialog) {
                    infowindow.open(map, marker);
                }

                /*
                if (result.geometry.bounds) {
                boundsOverlay = new google.maps.Rectangle({
                'bounds': result.geometry.bounds,
                'strokeColor': '#ff0000',
                'strokeOpacity': 1.0,
                'strokeWeight': 2.0,
                'fillOpacity': 0.0
                });
                boundsOverlay.setMap(map);
                google.maps.event.addListener(boundsOverlay, 'click', onClickCallback);
                document.getElementById('boundsLegend').style.display = 'block';
                } else {
                boundsOverlay = null;
                }
                */
                /*
                viewportOverlay = new google.maps.Rectangle({
                'bounds': result.geometry.viewport,
                'strokeColor': '#0000ff',
                'strokeOpacity': 1.0,
                'strokeWeight': 2.0,
                'fillOpacity': 0.0
                });
                viewportOverlay.setMap(map);
                google.maps.event.addListener(viewportOverlay, 'click', onClickCallback);
                document.getElementById('viewportLegend').style.display = 'block';
                */

                //document.getElementById('p' + resultNum).style.backgroundColor = "#eeeeff";
                //document.getElementById('matches').scrollTop =
                //document.getElementById('p' + resultNum).offsetTop -
                //document.getElementById('matches').offsetTop;
                selected = resultNum;
            }
        }

        var isPinPlaced = false;
        for (var i = 0; i < results.length; i++) {
            if (isPinPlaced) break;
            if (results[i].types == 'street_address' || results[i].types == 'route' || results[i].types == 'intersection') {
                var icon = new google.maps.MarkerImage(
                  getMarkerImageUrl(i),
                  new google.maps.Size(20, 34),
                  new google.maps.Point(0, 0),
                  new google.maps.Point(10, 34)
                );

                markers[i] = new google.maps.Marker({
                    'position': results[i].geometry.location,
                    'map': map,
                    'icon': icon,
                    'shadow': shadow
                });


                google.maps.event.addListener(markers[i], 'click', openInfoWindow(i, results[i], markers[i]));
                isPinPlaced = true;

                //resultsListHtml += getResultsListItem(i, getResultDescription(results[i]));
                if (results[i].types.join(", ") == "street_address") {
                    resultsListHtml += getResultsListItem(i, getResultDescription(results[i]));
                }
            }
        }

        //document.getElementById("matches").innerHTML = resultsListHtml;
        //document.getElementById("p0").style.border = "none";
        //document.getElementById("matches").style.display = "block";

        if (reverse) {
            // make a smooth movement to the clicked position
            map.panTo(clickMarker.getPosition());
            google.maps.event.addListenerOnce(map, 'idle', function() {
                selectMarker(0);
            });
        }

        else {
            zoomToViewports(results);
            selectMarker(0);
        }


    }

    function selectMarker(n) {
        if (showMarkerDialog) {
            if (markers[n] != null) {
                google.maps.event.trigger(markers[n], 'click');
            }
        }
    }

    function zoomToViewports(results) {
        var bounds = new google.maps.LatLngBounds();

        for (var i in results) {
            bounds.union(results[i].geometry.viewport);
        }

        map.fitBounds(bounds);
    }

    function getMarkerImageUrl(resultNum) {
        return MAPFILES_URL + "marker" + String.fromCharCode(65 + resultNum) + ".png";
    }

    function getResultsListItem(resultNum, resultDescription) {
        var html = '<a onclick="selectMarker(' + resultNum + ')">';
        html += '<div class="info" id="p' + resultNum + '">';
        html += '<table><tr valign="top">';
        html += '<td style="padding: 2px"><img src="' + getMarkerImageUrl(resultNum) + '"/></td>';
        html += '<td style="padding: 2px">' + resultDescription + '</td>';
        html += '</tr></table>';
        html += '</div></a>';
        return html;
    }

    function getResultDescription(result) {
        var bounds = result.geometry.bounds;
        var html = '<table class="tabContent">';
        html += tr('Address', result.formatted_address);
        html += tr('Types', result.types.join(", "));
        html += tr('Location', result.geometry.location.toString());
        html += tr('Bounds', (bounds ? boundsToHtml(bounds) : "None"));
        html += tr('Viewport', boundsToHtml(result.geometry.viewport));
        html += tr('Location type', result.geometry.location_type);
        if (result.partial_match) {
            html += tr('Partial match', 'Yes');
        }
        html += '</table>';
        return html;
    }

    function getAddressComponentsHtml(result) {
        var sNumber = getData('street_number', result.address_components, true);

        var rangehtml = "";
        var isRange = false;
        if (sNumber.indexOf('-') > 0) {
            var hyphenIndex = 0;
            if (isNaN(sNumber)) {
                isRange = isNaN(parseInt(sNumber)) ? false : true;
                hyphenIndex = sNumber.indexOf("-");
                if (isRange) isRange = hyphenIndex > 0 ? true : false;
            }

            var beginRange = 0;
            var endRange = 0;
            if (isRange) {
                beginRange = sNumber.substring(0, hyphenIndex);
                endRange = sNumber.substring(hyphenIndex, sNumber.length);
                endRange = endRange.replace("-", "");
                var begin = parseInt(beginRange);
                var end = parseInt(endRange);

                rangehtml += "<tr>";
                rangehtml += "<td>";
                rangehtml += "<div style='padding-top:10px;'>";
                rangehtml += "<div id='alert_range'>";
                rangehtml += "<span style='color:red;font-weight:bold;width:100%;padding-bottom:5px;'>Please select a street number.</span>";
                rangehtml += "<br class='clear' />";
                rangehtml += "<select style='WIDTH: 200px' id='range_select' name='range_select' onchange='javascript:setAddressNumber();'>";
                rangehtml += "<option value='-1' selected>choose a number</option>";
                for (var i=begin; i <= end; i++)
                {
                    rangehtml += "<option value='" + i + "'>" + i + "</option>";
                }
                rangehtml += "</select>";
                rangehtml += "</div>";
                rangehtml += "</div>";
                rangehtml += "</td></tr>";
            }
        }

        var windowClass = isRange ? "infoWindowContent2" : "infoWindowContent";
        var html = "<div class='" + windowClass + "'>" +
                   "<input type='hidden' id='rangeNumber' name='rangeNumber' value='" + sNumber + "' />" +
                   "<table class='tabContent'>";
        html += tr('Address', result.formatted_address);

        html += rangehtml;
        /*
        html += "<tr><td>";
        html += "<div style='padding-top:10px;'>";
        html += "<button type='button'>Accept this Address</button>";
        html += "</div>";
        html += "</td></tr>";
        */
        html += '</table></div>';
        return html;
    }

    function setAddressNumber() {
        var number = $('#range_select').val();
        var rangeNumber = $('#rangeNumber').val();
        var address = $('#Address_StreetAddress').val();
        address = address.replace(rangeNumber, number);
        $('#Address_StreetAddress').val(address);
        submitQuery();
        $('#alert_range').hide();

    }

    function setAddress(address, city, state) {
        $('#Address_StreetAddress').val(address);
        $('#Address_City').val(city.toString().toUpperCase());
        $('#Address_State').val(state.toString().toUpperCase());
    }

    //function tr(key, value) {
    //    return '<tr>' +
    //       '<td class="key">' + key + (key ? ':' : '') + '</td>' +
    //       '<td class="value">' + value + '</td>' +
    //     '</tr>';
    //}

    function tr(key, value) {
        return '<tr>' +
           '<td class="key">' + key + (key ? ':' : '') + '</td></tr>' +
           '<tr><td class="value">' + value + '</td>' +
         '</tr>';
    }

    function br() {
        return '<tr><td colspan="2"><div style="width: 100%; border-bottom: 1px solid grey; margin: 2px;"</td></tr>';
    }

    function clearBoundsOverlays() {
        if (boundsOverlay != null) {
            boundsOverlay.setMap(null);
            document.getElementById('boundsLegend').style.display = 'none';
        }
        if (viewportOverlay != null) {
            viewportOverlay.setMap(null);
            document.getElementById('viewportLegend').style.display = 'none';
        }
    }

    function boundsToHtml(bounds) {
        return '(' + bounds.getSouthWest().toUrlValue(6) + ') -<br/>(' + bounds.getNorthEast().toUrlValue(6) + ')';
    }
