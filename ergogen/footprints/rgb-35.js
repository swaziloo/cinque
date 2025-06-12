module.exports = {
    params: {
        designator: 'LED',
        side: 'F',
	counter: '',
        DIN: undefined,
        DOUT: undefined,
        VCC: {type: 'net', value: 'VCC'},
        GND: {type: 'net', value: 'GND'}
    },
    body: p => `
    
        (module WS2812B (layer F.Cu) (tedit 53BEE615)

            ${p.at /* parametric position */}

            ${'' /* footprint reference */}
            (fp_text reference "${p.counter}" (at 0 0 ${p.rot}) 
	      (layer ${p.side}.SilkS knockout)
	      (effects (font (size 1 1) (thickness 0.16))
	        (justify ${p.side == 'B' ? 'mirror' : ''})
              )
	    )
	    
            (fp_line (start 2.8 -0.4) (end 2.8 -1.8) (layer ${p.side}.SilkS) (width 0.2))
            (fp_line (start 2.8 -1.8) (end 0.9 -1.8) (layer ${p.side}.SilkS) (width 0.2))

            (pad 1 smd rect (at -1.65 -0.9 ${p.r}) (size 1.5 1) (layers ${p.side}.Cu ${p.side}.Paste ${p.side}.Mask) ${p.DOUT})
            (pad 2 smd rect (at -1.65 0.9 ${p.r}) (size 1.5 1) (layers ${p.side}.Cu ${p.side}.Paste ${p.side}.Mask) ${p.VCC})
            (pad 3 smd rect (at 1.65 0.9 ${p.r}) (size 1.5 1) (layers ${p.side}.Cu ${p.side}.Paste ${p.side}.Mask) ${p.DIN})
            (pad 4 smd rect (at 1.65 -0.9 ${p.r}) (size 1.5 1) (layers ${p.side}.Cu ${p.side}.Paste ${p.side}.Mask) ${p.GND})
            
        )
    
    `
}
