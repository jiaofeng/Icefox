/* Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 */

// This verifies that add-ons with invalid target application entries show
// up in the API but are correctly appDisabled

// A working add-on
var addon1 = {
  id: "addon1@tests.mozilla.org",
  version: "1.0",
  name: "Test 1",
  targetApplications: [{
    id: "xpcshell@tests.mozilla.org",
    minVersion: "1",
    maxVersion: "1"
  }]
};

// Missing id
var addon2 = {
  id: "addon2@tests.mozilla.org",
  version: "1.0",
  name: "Test 2",
  targetApplications: [{
    minVersion: "1",
    maxVersion: "2"
  }]
};

// Missing minVersion
var addon3 = {
  id: "addon3@tests.mozilla.org",
  version: "1.0",
  name: "Test 3",
  targetApplications: [{
    id: "xpcshell@tests.mozilla.org",
    maxVersion: "1"
  }]
};

// Missing maxVersion
var addon4 = {
  id: "addon4@tests.mozilla.org",
  version: "1.0",
  name: "Test 4",
  targetApplications: [{
    id: "xpcshell@tests.mozilla.org",
    minVersion: "1"
  }]
};

// Blank id
var addon5 = {
  id: "addon5@tests.mozilla.org",
  version: "1.0",
  name: "Test 5",
  targetApplications: [{
    id: "",
    minVersion: "1",
    maxVersion: "2"
  }]
};

// Blank minVersion
var addon6 = {
  id: "addon6@tests.mozilla.org",
  version: "1.0",
  name: "Test 6",
  targetApplications: [{
    id: "xpcshell@tests.mozilla.org",
    minVersion: "",
    maxVersion: "1"
  }]
};

// Blank maxVersion
var addon7 = {
  id: "addon7@tests.mozilla.org",
  version: "1.0",
  name: "Test 7",
  targetApplications: [{
    id: "xpcshell@tests.mozilla.org",
    minVersion: "1",
    maxVersion: ""
  }]
};

createAppInfo("xpcshell@tests.mozilla.org", "XPCShell", "1", "1.9.2");

const profileDir = gProfD.clone();
profileDir.append("extensions");

// Set up the profile
function run_test() {
  do_test_pending();

  var dest = profileDir.clone();
  dest.append("addon1@tests.mozilla.org");
  writeInstallRDFToDir(addon1, dest);
  dest = profileDir.clone();
  dest.append("addon2@tests.mozilla.org");
  writeInstallRDFToDir(addon2, dest);
  dest = profileDir.clone();
  dest.append("addon3@tests.mozilla.org");
  writeInstallRDFToDir(addon3, dest);
  dest = profileDir.clone();
  dest.append("addon4@tests.mozilla.org");
  writeInstallRDFToDir(addon4, dest);
  dest = profileDir.clone();
  dest.append("addon5@tests.mozilla.org");
  writeInstallRDFToDir(addon5, dest);
  dest = profileDir.clone();
  dest.append("addon6@tests.mozilla.org");
  writeInstallRDFToDir(addon6, dest);
  dest = profileDir.clone();
  dest.append("addon7@tests.mozilla.org");
  writeInstallRDFToDir(addon7, dest);

  startupManager();

  AddonManager.getAddonsByIDs(["addon1@tests.mozilla.org",
                               "addon2@tests.mozilla.org",
                               "addon3@tests.mozilla.org",
                               "addon4@tests.mozilla.org",
                               "addon5@tests.mozilla.org",
                               "addon6@tests.mozilla.org",
                               "addon7@tests.mozilla.org"],
                               function([a1, a2, a3, a4, a5, a6, a7]) {
    do_check_neq(a1, null);
    do_check_false(a1.appDisabled);
    do_check_true(a1.isActive);

    do_check_neq(a2, null);
    do_check_true(a2.appDisabled);
    do_check_false(a2.isActive);

    do_check_neq(a3, null);
    do_check_true(a3.appDisabled);
    do_check_false(a3.isActive);

    do_check_neq(a4, null);
    do_check_true(a4.appDisabled);
    do_check_false(a4.isActive);

    do_check_neq(a5, null);
    do_check_true(a5.appDisabled);
    do_check_false(a5.isActive);

    do_check_neq(a6, null);
    do_check_true(a6.appDisabled);
    do_check_false(a6.isActive);

    do_check_neq(a6, null);
    do_check_true(a6.appDisabled);
    do_check_false(a6.isActive);

    do_test_finished();

  });
}
