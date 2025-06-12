// Panasonic EVQWGD001 horizontal rotary encoder
//
//   __________________
//  (f) (t)         | |
//  | (1)           | |
//  | (2)           | |
//  | (3)           | |
//  | (4)           | |
//  |_( )___________|_|
//
// Nets
//    from: corresponds to switch pin 1 (for button presses)
//    to: corresponds to switch pin 2 (for button presses)
//    A: corresponds to pin 1 (for rotary)
//    B: corresponds to pin 2 (for rotary, should be GND)
//    C: corresponds to pin 3 (for rotary)
//    D: corresponds to pin 4 (for rotary, unused)
// Params
//    reverse: default is false
//      if true, will flip the footprint such that the pcb can be reversible
//
// Modified 8/2024 by swaziloo to refine measurements


module.exports = {
    params: {
      designator: 'S',
		  reverse: false,
      from: undefined,
      to: undefined,
      A: undefined,
      B: undefined,
      C: undefined,
      D: undefined
    },
    body: p => {
      const standard = `
        (module RollerEncoder_Panasonic_EVQWGD001 (layer F.Cu) (tedit 6040A10C)
        ${p.at /* parametric position */}   
        (fp_text reference REF** (at 0 0 ${p.r}) (layer F.Fab) (effects (font (size 1 1) (thickness 0.15))))
        (fp_text value Encoder_Panasonic_EVQWGD001 (at -0.1 9 ${p.r}) (layer F.Fab) (effects (font (size 1 1) (thickness 0.15))))
        
        ${'' /* corner marks */}
        (fp_line (start -8.375 -7.0) (end 8.375 -7.0) (layer Dwgs.User) (width 0.1))
        (fp_line (start 8.375 -7.0) (end 8.375 7.0) (layer Dwgs.User) (width 0.1))
        (fp_line (start 8.375 7.0) (end -8.375 7.0) (layer Dwgs.User) (width 0.1))
        (fp_line (start -8.375 7.0) (end -8.375 -7.0) (layer Dwgs.User) (width 0.1))

        ${'' /* hook */}
        (fp_line (start 7.0 7.0) (end 7.0 4.0) (layer Dwgs.User) (width 0.1))
        (fp_line (start 7.0 4.0) (end 6.0 4.0) (layer Dwgs.User) (width 0.1))
        (fp_line (start 6.0 4.0) (end 6.0 2.0) (layer Dwgs.User) (width 0.1))
	(fp_line (start 6.0 2.0) (end 7.0 2.0) (layer Dwgs.User) (width 0.1))
	(fp_line (start 7.0 2.0) (end 7.0 -3.0) (layer Dwgs.User) (width 0.1))
        (fp_line (start 7.0 -3.0) (end 6.0 -3.0) (layer Dwgs.User) (width 0.1))
        (fp_line (start 6.0 -3.0) (end 6.0 -5.0) (layer Dwgs.User) (width 0.1))
        (fp_line (start 6.0 -5.0) (end 7.0 -5.0) (layer Dwgs.User) (width 0.1))
        (fp_line (start 7.0 -5.0) (end 7.0 -7.0) (layer Dwgs.User) (width 0.1))
      `
      function pins(def_neg, def_pos) {
        return `
          ${'' /* edge cuts */}
          (fp_line (start ${def_pos}9.4 7) (end ${def_pos}9.4 -7.0) (layer Edge.Cuts) (width 0.15))
          (fp_line (start ${def_pos}7.0 7.0) (end ${def_pos}7.0 -7.0) (layer Edge.Cuts) (width 0.15))
          (fp_line (start ${def_pos}9.1 -7.3) (end ${def_pos}7.3 -7.3) (layer Edge.Cuts) (width 0.15))
          (fp_line (start ${def_pos}7.3 7.3) (end ${def_pos}9.1 7.3) (layer Edge.Cuts) (width 0.15))

          (fp_arc (start ${def_pos}7.3 7.0) (end ${def_pos}7.0 7.0) (angle ${def_neg}90) (layer Edge.Cuts) (width 0.15))
          (fp_arc (start ${def_pos}9.1 7.0) (end ${def_pos}9.1 7.3) (angle ${def_neg}90) (layer Edge.Cuts) (width 0.15))
          (fp_arc (start ${def_pos}9.1 -7) (end ${def_pos}9.4 -7) (angle ${def_neg}90) (layer Edge.Cuts) (width 0.15))
          (fp_arc (start ${def_pos}7.3 -7.0) (end ${def_pos}7.3 -7.3) (angle ${def_neg}90) (layer Edge.Cuts) (width 0.15))

          ${'' /* pins */}
          (pad S1 thru_hole circle (at ${def_neg}7.375 -6.85 ${p.r}) (size 1.6 1.6) (drill 0.9) (layers *.Cu *.Mask) ${p.from})
          (pad S2 thru_hole circle (at ${def_neg}5.375 -6.85 ${p.r}) (size 1.6 1.6) (drill 0.9) (layers *.Cu *.Mask) ${p.to})
          (pad A thru_hole circle (at ${def_neg}5.875 -4.16 ${p.r}) (size 1.6 1.6) (drill 0.9) (layers *.Cu *.Mask) ${p.A})
          (pad B thru_hole circle (at ${def_neg}5.875 -1.62 ${p.r}) (size 1.6 1.6) (drill 0.9) (layers *.Cu *.Mask) ${p.B})
          (pad C thru_hole circle (at ${def_neg}5.875 0.92 ${p.r}) (size 1.6 1.6) (drill 0.9) (layers *.Cu *.Mask) ${p.C})
          (pad D thru_hole circle (at ${def_neg}5.875 3.46 ${p.r}) (size 1.6 1.6) (drill 0.9) (layers *.Cu *.Mask) ${p.D})

          ${'' /* stabilizer */}
          (pad "" np_thru_hole circle (at ${def_neg}5.875 6.0 ${p.r}) (size 1.5 1.5) (drill 1.5) (layers *.Cu *.Mask))
        `
    }
    if(p.reverse) {
      return `
        ${standard}
        ${pins('-', '')}
        ${pins('', '-')})
        `
    } else {
      return `
        ${standard}
        ${pins('-', '')})
        `
    }
  }
}
