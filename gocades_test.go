package gocades

import (
	"testing"
)

func TestAbout(t *testing.T) {
	about, _ := About()
	about.GetVersion()
	about.GetMajorVersion()
	about.GetMinorVersion()
	about.GetBuildVersion()
	about.GetCSPVersion("", 80)
	about.GetCSPName(80)
	about.MediaFilter(MEDIA_TYPE_SCARD)
	about.ReaderFilter(ENABLE_ANY_CARRIER_TYPE, DISABLE_EVERY_CARRIER_OPERATION, ".*rutoken.*")
}

func TestVersion(t *testing.T) {
	about, _ := About()
	version, _ := about.GetCSPVersion("", 80)
	version.ToString()
	version.GetMajorVersion()
	version.GetMinorVersion()
	version.GetBuildVersion()
}

func TestAttribute(t *testing.T) {
	attribute, _ := Attribute()
	attribute.PutValue("ABCD")
	attribute.GetValue()
	attribute.PutName(2)
	attribute.GetName()
	attribute.PutValueEncoding(1)
	attribute.GetValueEncoding()
	attribute.PutOID("1.2.3.3.5")
	attribute.GetOID()
}

func TestOID(t *testing.T) {
	attribute, _ := Attribute()
	oid, _ := attribute.GetOID()
	oid.SetFriendlyName("ГОСТ Р 34.10-2001")
	oid.GetFriendlyName()
	oid.GetValue()
	oid.SetValue("1.2.643.7.1.1.2.2")
	oid.GetFriendlyName()
	oid.SetName(1)
	oid.GetName()
	oid.GetValue()
}

func TestLicense(t *testing.T) {
	license, _ := License()
	license.SetLicense("5050EF301001FCZCT9M0HNAUV", "UserName", "CompanyName")
	license.GetCompanyName(0)
	license.GetFirstInstallDate(0)
	license.GetSerialNumber(0)
	license.GetType(0)
	license.GetValidTo(0)
}

func TestCRL(t *testing.T) {
	crl, _ := CRL()
	s := "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"
	crl.Import(s)
	crl.GetIssuerName()
	crl.GetThisUpdate()
	crl.GetNextUpdate()
	crl.GetThumbprint()
	crl.GetAuthKeyID()
	crl.Export(CADESCOM_ENCODE_BASE64)
}
