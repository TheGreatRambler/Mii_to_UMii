// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "gen3_studio.h"
namespace Kaitai {

	gen3_studio_t::gen3_studio_t (kaitai::kstream* p__io, kaitai::kstruct* p__parent, gen3_studio_t* p__root)
		: kaitai::kstruct (p__io) {
		m__parent = p__parent;
		m__root   = this;
		_read ();
	}

	void gen3_studio_t::_read () {
		m_facial_hair_color  = m__io->read_u1 ();
		m_beard_goatee       = m__io->read_u1 ();
		m_body_weight        = m__io->read_u1 ();
		m_eye_stretch        = m__io->read_u1 ();
		m_eye_color          = m__io->read_u1 ();
		m_eye_rotation       = m__io->read_u1 ();
		m_eye_size           = m__io->read_u1 ();
		m_eye_type           = m__io->read_u1 ();
		m_eye_horizontal     = m__io->read_u1 ();
		m_eye_vertical       = m__io->read_u1 ();
		m_eyebrow_stretch    = m__io->read_u1 ();
		m_eyebrow_color      = m__io->read_u1 ();
		m_eyebrow_rotation   = m__io->read_u1 ();
		m_eyebrow_size       = m__io->read_u1 ();
		m_eyebrow_type       = m__io->read_u1 ();
		m_eyebrow_horizontal = m__io->read_u1 ();
		m_eyebrow_vertical   = m__io->read_u1 ();
		m_face_color         = m__io->read_u1 ();
		m_face_makeup        = m__io->read_u1 ();
		m_face_type          = m__io->read_u1 ();
		m_face_wrinkles      = m__io->read_u1 ();
		m_favorite_color     = m__io->read_u1 ();
		m_gender             = m__io->read_u1 ();
		m_glasses_color      = m__io->read_u1 ();
		m_glasses_size       = m__io->read_u1 ();
		m_glasses_type       = m__io->read_u1 ();
		m_glasses_vertical   = m__io->read_u1 ();
		m_hair_color         = m__io->read_u1 ();
		m_hair_flip          = m__io->read_u1 ();
		m_hair_type          = m__io->read_u1 ();
		m_body_height        = m__io->read_u1 ();
		m_mole_size          = m__io->read_u1 ();
		m_mole_enable        = m__io->read_u1 ();
		m_mole_horizontal    = m__io->read_u1 ();
		m_mole_vertical      = m__io->read_u1 ();
		m_mouth_stretch      = m__io->read_u1 ();
		m_mouth_color        = m__io->read_u1 ();
		m_mouth_size         = m__io->read_u1 ();
		m_mouth_type         = m__io->read_u1 ();
		m_mouth_vertical     = m__io->read_u1 ();
		m_beard_size         = m__io->read_u1 ();
		m_beard_mustache     = m__io->read_u1 ();
		m_beard_vertical     = m__io->read_u1 ();
		m_nose_size          = m__io->read_u1 ();
		m_nose_type          = m__io->read_u1 ();
		m_nose_vertical      = m__io->read_u1 ();
	}

	gen3_studio_t::~gen3_studio_t () {
		_clean_up ();
	}

	void gen3_studio_t::_clean_up () {
	}
}
