PULSONIX_LIBRARY_ASCII "SamacSys ECAD Model"
//471759/1159423/2.50/3/3/Transistor BJT NPN

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r64_48"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 0.48) (shapeHeight 0.64))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Normal"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 1.27)
			(strokeWidth 0.127)
		)
	)
	(patternDef "SOTFL50P160X85-3N" (originalName "SOTFL50P160X85-3N")
		(multiLayer
			(pad (padNum 1) (padStyleRef r64_48) (pt -0.75, 0.5) (rotation 90))
			(pad (padNum 2) (padStyleRef r64_48) (pt -0.75, -0.5) (rotation 90))
			(pad (padNum 3) (padStyleRef r64_48) (pt 0.75, 0) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0, 0) (textStyleRef "Normal") (isVisible True))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -1.22 1) (pt 1.22 1) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 1.22 1) (pt 1.22 -1) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 1.22 -1) (pt -1.22 -1) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -1.22 -1) (pt -1.22 1) (width 0.05))
		)
		(layerContents (layerNumRef 28)
			(line (pt -0.43 0.8) (pt 0.43 0.8) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 0.43 0.8) (pt 0.43 -0.8) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 0.43 -0.8) (pt -0.43 -0.8) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -0.43 -0.8) (pt -0.43 0.8) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -0.43 0.3) (pt 0.07 0.8) (width 0.025))
		)
		(layerContents (layerNumRef 18)
			(line (pt -0.08 0.8) (pt 0.08 0.8) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 0.08 0.8) (pt 0.08 -0.8) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 0.08 -0.8) (pt -0.08 -0.8) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -0.08 -0.8) (pt -0.08 0.8) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.07 0.99) (pt -0.43 0.99) (width 0.2))
		)
	)
	(symbolDef "DTC143ZEBTL" (originalName "DTC143ZEBTL")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 0 mils -45 mils) (rotation 0]) (justify "UpperLeft") (textStyleRef "Normal"))
		))
		(pin (pinNum 2) (pt 400 mils -300 mils) (rotation 90) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 405 mils -300 mils) (rotation 90]) (justify "LowerLeft") (textStyleRef "Normal"))
		))
		(pin (pinNum 3) (pt 400 mils 300 mils) (rotation 270) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 405 mils 300 mils) (rotation 90]) (justify "UpperLeft") (textStyleRef "Normal"))
		))
		(line (pt 300 mils 100 mils) (pt 300 mils -100 mils) (width 20 mils))
		(line (pt 300 mils 50 mils) (pt 400 mils 150 mils) (width 6 mils))
		(line (pt 300 mils -50 mils) (pt 400 mils -150 mils) (width 6 mils))
		(line (pt 400 mils -150 mils) (pt 400 mils -200 mils) (width 6 mils))
		(line (pt 400 mils 150 mils) (pt 400 mils 200 mils) (width 6 mils))
		(line (pt 100 mils 0 mils) (pt 300 mils 0 mils) (width 6 mils))
		(arc (pt 350 mils 0 mils) (radius 158.114 mils) (startAngle 0) (sweepAngle 360) (width 10  mils))
		(poly (pt 330 mils -100 mils) (pt 350 mils -80 mils) (pt 370 mils -120 mils) (pt 330 mils -100 mils) (width 10  mils))
		(attr "RefDes" "RefDes" (pt 550 mils 50 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))
		(attr "Type" "Type" (pt 550 mils -50 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))

	)
	(compDef "DTC143ZEBTL" (originalName "DTC143ZEBTL") (compHeader (numPins 3) (numParts 1) (refDesPrefix Q)
		)
		(compPin "1" (pinName "B") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "E") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "3" (pinName "C") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "DTC143ZEBTL"))
		(attachedPattern (patternNum 1) (patternName "SOTFL50P160X85-3N")
			(numPads 3)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
			)
		)
		(attr "Manufacturer_Name" "ROHM Semiconductor")
		(attr "Manufacturer_Part_Number" "DTC143ZEBTL")
		(attr "Mouser Part Number" "755-DTC143ZEBTL")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/ROHM-Semiconductor/DTC143ZEBTL?qs=IsRgwgmxh6%252Bn%252Bp0edl8N%2Fw%3D%3D")
		(attr "Arrow Part Number" "DTC143ZEBTL")
		(attr "Arrow Price/Stock" "https://www.arrow.com/en/products/dtc143zebtl/rohm-semiconductor")
		(attr "Description" "ROHM, DTC143ZEBTL NPN Digital Transistor, 100 mA 50 V 4.7 k, Ratio Of 10, 3-Pin SC-89")
		(attr "<Hyperlink>" "https://datasheet.datasheetarchive.com/originals/distributors/Datasheets_SAMA/65f79013acac3be2ce67f49282ff3c06.pdf")
		(attr "<Component Height>" "0.85")
		(attr "<STEP Filename>" "DTC143ZEBTL.stp")
		(attr "<STEP Offsets>" "X=0;Y=0;Z=0")
		(attr "<STEP Rotation>" "X=0;Y=0;Z=0")
	)

)
